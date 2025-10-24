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

void solve()
{
    i64 n;
    cin >> n;
    vvint g(n + 1);
    for (i64 i = 0; i < n - 1; i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vint dep(n + 1);
    vint par(n + 1), chi(n + 1);
    auto dfs = [&](auto &&self, i64 p, i64 c) -> void {
        if (p != -1) dep[c] = dep[p] + 1;
        par[c] = p;
        for (auto &&v : g[c]) {
            if (v == p) continue;
            self(self, c, v);
            chi[c]++;
        }
    };
    dfs(dfs, -1, n);
    vvint lea(2);
    for (i64 i = 1; i <= n; i++) {
        if (chi[i] == 0) {
            lea[dep[i] & 1].push_back(i);
        }
    }
    vpii ans;
    i64 cur = dep[1] & 1;
    for (i64 i = 0; i < n - 1; i++) {
        if (lea[cur ^ 1].empty()) {
            ans.emplace_back(1, -1);
            cur ^= 1;
        }
        i64 next = lea[cur ^ 1].back();
        lea[cur ^ 1].pop_back();
        ans.emplace_back(2, next);
        i64 p = par[next];
        if (p != -1) {
            chi[p]--;
            if (chi[p] == 0) {
                lea[dep[p] & 1].push_back(p);
            }
        }
        ans.emplace_back(1, -1);
        cur ^= 1;
    }
    cout << ans.size() << endl;
    for (auto &&[i, j] : ans) {
        if (i == 1)
            cout << 1 << endl;
        else
            cout << "2 " << j << endl;
    }
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