#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

constexpr const i64 MOD = 1000000007;

i64 ksm(i64 a, i64 b)
{
    a %= MOD;
    if (a < 0) a += MOD;
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    i64 n, m;
    if (!(cin >> n >> m)) return;
    // 最大 k 满足 k(k+1)/2 <= n
    i64 kmax = 0;
    while (kmax * (kmax + 1) / 2 <= n) ++kmax;
    --kmax;
    if (kmax < 0) kmax = 0;

    // dp[t][s]: 用恰好 t 个不同正整数构成和为 s 的方案数
    i64 K = kmax;
    i64 N = n;
    vector<vector<i64>> dp(K + 1, vector<i64>(N + 1, 0));
    dp[0][0] = 1;

    for (i64 v = 1; v <= N; v++) {
        for (i64 t = K; t >= 1; t--) {
            for (i64 s = N; s >= v; s--) {
                dp[t][s] += dp[t - 1][s - v];
                if (dp[t][s] >= MOD) dp[t][s] -= MOD;
            }
        }
    }

    i64 ans = 0;
    for (i64 k = 1; k <= K; k++) {
        i64 ways = dp[k][N] % MOD;
        if (ways == 0) continue;
        ways = ways * (m % MOD) % MOD;
        ways = ways * ksm((m - 1) % MOD, k - 1) % MOD;
        ans += ways;
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans % MOD << endl;
}
//

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