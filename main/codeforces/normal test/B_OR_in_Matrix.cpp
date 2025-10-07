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
    i64 n, m;
    cin >> n >> m;
    vvint mp(n + 1, vint(m + 1));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    vvint mp2(n + 1, vint(m + 1, -1));
    auto tr = [&](i64 y, i64 x) -> void {
        for (i64 i = 1; i <= m; i++) {
            mp2[y][i] = 0;
        }
        for (i64 i = 1; i <= n; i++) {
            mp2[i][x] = 0;
        }
    };
    auto check = [&](i64 y, i64 x) -> bool {
        bool ok = 0;
        for (i64 i = 1; i <= m; i++) {
            if (mp2[y][i] == 1) ok = 1;
        }
        for (i64 i = 1; i <= n; i++) {
            if (mp2[i][x] == 1) ok = 1;
        }
        return ok;
    };
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (mp[i][j] == 0) {
                tr(i, j);
            }
            else {
                if (mp2[i][j] == -1) mp2[i][j] = 1;
            }
        }
    }
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (mp[i][j] == 1) {
                if (!check(i, j)) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            cout << mp2[i][j] << " ";
        }
        cout << endl;
    }
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