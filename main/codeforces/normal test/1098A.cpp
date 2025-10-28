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
    vint par(n + 1);
    for (i64 i = 2; i <= n; i++) {
        i64 x = 0;
        cin >> x;
        g[x].emplace_back(i);
        par[i] = x;
    }
    vint s(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vint deep(n + 1, 1);
    auto dfs = [&](auto &&self, i64 p, i64 c) -> void {
        if (p != -1) deep[c] = deep[p] + 1;
        for (auto &&v : g[c]) {
            self(self, c, v);
        }
    };
    dfs(dfs, -1, 1);
    i64 ok = 1;
    vint a(n + 1, 0);
    if (s[1] == -1) ok = 0;
    auto dfs2 = [&](auto &&self, i64 u) -> void {
        if (!ok) return;
        i64 spar = (par[u] == 0 ? 0 : s[par[u]]);
        if ((deep[u] & 1) == 1) {
            // 奇数层
            if (s[u] == -1 || s[u] < spar) {
                ok = 0;
                return;
            }
            a[u] = s[u] - spar;
        }
        else {
            // 偶数层
            if (s[u] == -1) {
                if (g[u].empty()) {
                    s[u] = spar;
                }
                else {
                    i64 mn = LLONG_MAX;
                    for (auto &&w : g[u]) {
                        if (s[w] == -1) {
                            ok = 0;
                            return;
                        }
                        mn = min(mn, s[w]);
                    }
                    if (mn < spar) {
                        ok = 0;
                        return;
                    }
                    s[u] = mn;
                }
            }
            else {
                if (s[u] < spar) {
                    ok = 0;
                    return;
                }
            }
            a[u] = s[u] - spar;
        }
        for (auto &&w : g[u]) self(self, w);
    };

    if (ok) dfs2(dfs2, 1);
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    i64 tot = 0;
    for (i64 i = 1; i <= n; i++) tot += a[i];
    cout << tot << endl;
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