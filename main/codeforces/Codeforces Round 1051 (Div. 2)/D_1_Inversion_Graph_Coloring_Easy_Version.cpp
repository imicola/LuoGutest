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
constexpr i64 MOD = 1e9 + 7;

void solve()
{
    i64 n;
    cin >> n;
    vint a(n + 1, 0), b(n + 1, 0);
    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i64 i = 1; i <= n; i++) {
        b[i] = 1;
        for (i64 j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) b[i]++;
        }
        for (i64 j = 1; j < i; j++) {
            if (a[i] >= a[j]) b[i]++;
        }
    }
    // 每一个单独的子序列都是一个结果，其为1
    // dp[i][m][mp]表示前i个元素中选择的子序列的数目，最大的元素m以及我们规定的LDS = 2的最大值mp
    vector<vector<vector<i64>>> dp(2, vvint(n + 1, vint(n + 1, 0)));
    dp[0][0][0] = 1;
    i64 cr = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 x = b[i];
        cr ^= 1;
        for (i64 j = 0; j <= n; j++) {
            for (i64 k = 0; k <= n; k++) {
                dp[cr][j][k] = dp[cr ^ 1][j][k];
            }
        }
        for (i64 j = 0; j <= n; j++) {
            for (i64 k = 0; k <= j; k++) {
                // 如果前一个为0
                if (dp[cr ^ 1][j][k] == 0) continue;
                // a[i] > max
                if (j > x && x > k) dp[cr][j][x] = (dp[cr][j][x] + dp[cr ^ 1][j][k]) % MOD;
                // a[i] < max ，a[i] > mp
                if (x > j) dp[cr][x][k] = (dp[cr][x][k] + dp[cr ^ 1][j][k]) % MOD;
            }
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i <= n; i++) {
        for (i64 j = 0; j <= n; j++) {
            ans = (ans + dp[cr][i][j]) % MOD;
        }
    }
    cout << ans % MOD << endl;
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