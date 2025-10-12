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
    vint a(2 * n + 2);
    for (i64 i = 1; i <= n; i++) {
        i64 num;
        cin >> num;
        a[i] = num, a[n + i] = num;
    }
    i64 ans = 1e18;
    auto clac = [](i64 a, i64 b, i64 c) { return max({a, b, c}) - min({a, b, c}); };
    for (i64 l = 1; l <= 3; l++) {
        vint dp(n + 1, 1e18);
        dp[0] = 0;
        for (i64 i = 0; i < n; i++) {
            if (i + 2 <= n) {
                i64 cost = abs(a[i + l] - a[i + 1 + l]);
                dp[i + 2] = min(dp[i + 2], dp[i] + cost);
            }
            if (i + 3 <= n) {
                i64 cost = clac(a[l + i], a[l + i + 1], a[l + i + 2]);
                dp[i + 3] = min(dp[i + 3], dp[i] + cost);
            }
        }
        ans = min(ans, dp[n]);  
    }
    cout << ans << endl;
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