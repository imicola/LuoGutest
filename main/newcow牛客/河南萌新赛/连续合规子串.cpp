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
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vint dp(n, 1);
    if (s[0] != s[1]) dp[1] = 2;
    for (i64 i = 2; i < n; i++) {
        if (s[i] != s[i - 1] && s[i] != s[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            if (s[i] == s[i - 2]) dp[i] = 2;
            if (s[i] == s[i - 1]) dp[i] = 1;
        }
    }
    cout << ranges::max(dp);
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