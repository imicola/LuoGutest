//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vvint mp(21, vint(21));
    for (size_t i = 0; i < t; i++) {
        for (size_t j = 0; j < t; j++) {
            cin >> mp[i][j];
        }
    }
    vvint dp(1 << 21, vint(21, 0x3f3f3f));
    dp[1][0] = 0;
    for (size_t i = 0; i < (1 << t); i++) {
        for (size_t j = 0; j < t; j++) {
            if ((i >> j) & 1) {
                for (size_t k = 0; k < t; k++) {
                    if (((i >> k) & 1) == 0) {
                        dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], dp[i][j] + mp[j][k]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << t) - 1][t - 1];
    return 0;
}