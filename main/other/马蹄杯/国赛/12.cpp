#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v, begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vint> mp(m + 1, vint(m + 1));
    vector<vint> res(n + 1, vint(n + 1, 0));
    for (size_t i = 1; i <= m; i++) {
        for (size_t j = 1; j <= m; j++) {
            char c;
            cin >> c;
            mp[i][j] = (c == '#' ? 1 : 0);
        }
    }

    // 数组顺时针旋转
    // mp[i][j] = mp[n - j + 1][i]
    auto cer = [&]() -> void {
        vector<vint> tmp = mp;
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= m; j++) {
                mp[i][j] = tmp[m - j + 1][i];
            }
        }
    };
    auto yz = [&](int x, int y) -> void {
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= m; j++) {
                res[x + i - 1][y + j - 1] += mp[i][j];
            }
        }
    };
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            cer();
        }
        else {
            int x, y;
            cin >> x >> y;
            yz(x, y);
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}