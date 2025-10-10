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
    vint v(n);
    for (i64 i = 0; i < n; i++) {
        char c;
        cin >> c;
        v[i] = (c - '0');
    }
    // dp[i]到第i个的所有总和
    vint dp(n);
    dp[0] = 1;
    i64 cnt0 = (v[0] == 0);
    i64 cnt1 = (v[0] == 1);
    i64 cnt = 0, Max = -1;
    i64 tot = 0;
    for (i64 i = 1; i < n; i++) {
        if (v[i] == 1) cnt1++;
        if (v[i] == 0) cnt0++;
        Max = max(cnt0, cnt1);
        tot += Max;
        if (v[i] == v[i - 1] && v[i] == 0) {
            dp[i] = dp[i - 1] + 1 + cnt1 + tot;
        }
        if (v[i] == v[i - 1] && v[i] == 1) {
            dp[i] = dp[i - 1] + 1 + cnt0 + tot;
        }
        if (v[i] != v[i - 1]) {
            dp[i] = dp[i - 1] + 1 + tot + (v[i] == 0 ? cnt0 : cnt1);
            cnt = 0;
        }
        // cout << dp[i] << endl;
    }
    cout << dp[n - 1] << endl;
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