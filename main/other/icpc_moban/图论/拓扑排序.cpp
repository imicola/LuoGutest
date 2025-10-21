//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
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
        this->n = g.size();
        order.reserve(n);
        kahnsort(g);
    }
    void kahnsort(const vvint &g)
    {
        queue<i64> qu;
        vint indeg(n);
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

void solve() { }
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