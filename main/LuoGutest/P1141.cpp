//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vvint mp(n + 1, vint(n + 1));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            char c;
            cin >> c;
            mp[i][j] = (c == '0') ? 0 : 1;
        }
    }
    // 从每一个点开始跑bfs，能到达的点就在 res 中 +1,最后离线查询即可
    vvint res(n + 1, vint(n + 1, 0));
    vvint vis(n + 1, vint(n + 1, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            if (vis[i][j]) continue;
            queue<pii> qu;
            i64 ok = 0;
            vpii points;
            qu.emplace(i, j);
            points.emplace_back(i, j);
            while (!qu.empty()) {
                auto [x, y] = qu.front();
                qu.pop();
                i64 cur = mp[x][y];
                points.emplace_back(x, y);
                if (x + 1 <= n && cur != mp[x + 1][y] && !vis[x + 1][y]) {
                    qu.emplace(x + 1, y);
                    vis[x + 1][y] = 1;
                    ok++;
                }
                if (x - 1 > 0 && cur != mp[x - 1][y] && !vis[x - 1][y]) {
                    qu.emplace(x - 1, y);
                    vis[x - 1][y] = 1;
                    ok++;
                }
                if (y + 1 <= n && cur != mp[x][y + 1] && !vis[x][y + 1]) {
                    qu.emplace(x, y + 1);
                    vis[x][y + 1] = 1;
                    ok++;
                }
                if (y - 1 > 0 && cur != mp[x][y - 1] && !vis[x][y - 1]) {
                    qu.emplace(x, y - 1);
                    vis[x][y - 1] = 1;
                    ok++;
                }
            }
            for (auto [x, y] : points) {
                res[x][y] = ok;
            }
        }
    }
    while (m--) {
        i64 x, y;
        cin >> x >> y;
        cout << max(1ll, res[x][y]) << endl;
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