//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    vint p(n + 1, 0);
    vector<vector<i64>> adj(n + 1);
    for (i64 i = 1; i < n; i++) {
        i64 u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y) {
            adj[v].push_back(u);
            p[u]++;
        }
        else {
            adj[u].emplace_back(v);
            p[v]++;
        }
    }
    // 拓扑排序
    queue<i64> qu;
    for (i64 i = 1; i <= n; i++) {
        if (p[i] == 0) qu.push(i);
    }
    vint order;
    order.reserve(n);
    while (!qu.empty()) {
        i64 u = qu.front();
        qu.pop();
        order.push_back(u);
        for (auto &&i : adj[u]) {
            p[i]--;
            if (p[i] == 0) {
                qu.push(i);
            }
        }
    }
    vint res(n + 1);
    for (i64 i = 0; i < order.size(); i++) {
        res[order[i]] = i + 1;
    }
    for (i64 i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}