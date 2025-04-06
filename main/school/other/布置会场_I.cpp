//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

void solve()
{
    int t;
    cin >> t;
    int ans = 0;
    vint dp(t + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (size_t i = 3; i <= t; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[t] << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}