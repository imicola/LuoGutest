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
    vector<vector<int>> mp(n + 2, vector<int>(m + 2, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            char c;
            cin >> c;
            mp[i][j] = (c == '.' ? 0 : 1);
        }
    }
    auto f = [&](i64 i, i64 j) -> bool {
        if (mp[i][j] == 0) return true;
        i64 res = mp[i + 1][j] + mp[i - 1][j] + mp[i][j + 1] + mp[i][j - 1];
        return (res == 2 || res == 4);
    };

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (!f(i, j)) {
                cout << "No" << endl;
                // cout << i << " " << j;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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