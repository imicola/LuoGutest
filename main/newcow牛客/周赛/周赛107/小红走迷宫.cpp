//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    set<int> a;
    for (size_t i = 1; i <= x; i++) {
        int t;
        cin >> t;
        a.insert(t);
    }
    vvint gp(n + 1);
    vector<bool> vis(n + 1, false);
    for (size_t i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    queue<int> qu;
    qu.push(1);
    vis[1] = true;
    // set<int> res;
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (int i : gp[now]) {
            if (!vis[i] && !a.contains(i)) {
                vis[i] = 1;
                qu.push(i);
                // res.insert(now);
            }
        }
    }
    for (size_t i = 1; i <= n; i++)
    {
        if(vis[i]){
            cout << i << " ";
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}