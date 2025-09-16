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
constexpr i64 MOD = 998244353;
void solve()
{
    i64 n;
    cin >> n;
    vint a(n), b(n);
    for (auto &&i : a) {
        cin >> i;
    }
    for (auto &&i : b) {
        cin >> i;
    }
    vvint dp(n, vint(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    // dp[i][] 表示到第i组换不换
    for (i64 i = 1; i < n; i++) {
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
        }
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1])%MOD << endl;
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