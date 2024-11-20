//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vint dp(n + 1, 1e5);
        dp[3] = 1;
        dp[5] = 1;
        for (size_t i = 5; i <= n; i++) {
            dp[i] = min(min(dp[i], dp[i - 3] + 1), dp[i - 5] + 1);
        }
        if (dp[n] == 1e5)
            cout << -1;
        else
            cout << dp[n];
    }
    return 0;
}