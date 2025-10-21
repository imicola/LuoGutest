//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

struct Kahn
{
    vint order;
    i64 n;
    Kahn(const vvint &g)
    {
        this->n = g.size() - 1;
        kahnsort(g);
    }
    void kahnsort(const vvint &g)
    {
        queue<i64> qu;
        vint indeg(n + 1);
        for (i64 u = 1; u <= n; u++) {
            for (auto &&v : g[u]) {
                indeg[v]++;
            }
        }
        for (i64 i = 1; i <= n; i++) {
            if (indeg[i] == 0) qu.push(i);
        }
        while (!qu.empty()) {
            i64 u = qu.front();
            qu.pop();
            order.emplace_back(u);
            for (auto &&v : g[u]) {
                if (--indeg[v] == 0) qu.push(v);
            }
        }
    }
    vint get_order() const
    {
        return order;
    }
};

void solve()
{
    i64 n;
    cin >> n;
    vvint g(n + 1);
    for (i64 i = 1; i <= n; i++) {
        i64 x;
        while (1) {
            cin >> x;
            if (x == 0) break;
            g[i].emplace_back(x);
        }
    }
    Kahn ka(g);
    vint res = ka.get_order();
    for (auto &&i : res) {
        cout << i << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}