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
    vvint mp(n + 2, vint(m + 2, 0));
    vint X = {1, -1, 0, 0, 1, 1, -1, -1};
    vint Y = {0, 0, 1, -1, 1, -1, 1, -1};
    auto add = [&](i64 x, i64 y) -> void {
        mp[x][y] = 0x3f4f5f;
        for (i64 i = 0; i < 8; i++) {
            mp[x + X[i]][y + Y[i]]++;
        }
    };
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                add(i, j);
            }
        }
    }
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (mp[i][j] >= 0x3f4f5f) {
                cout << '*';
            }
            else {
                cout << mp[i][j];
            }
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