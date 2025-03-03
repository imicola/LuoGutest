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

void solve()
{
    int n, m;
    cin >> n >> m;
    vint val(m, 0), size(m, 0);
    for (size_t i = 0; i < m; i++) {
        int temp;
        cin >> size[i] >> temp;
        val[i] = size[i] * temp;
    }
    vvint dp(m, vint(n + 1, 0));
    for (size_t i = 0; i < m; i++) {
        dp[i][0] = 0;
    }
    for (size_t i = size[0]; i <= n; i++) {
        dp[0][i] = val[0];
    }
    for (size_t i = 1; i < m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if(j < size[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size[i]] + val[i]);
            }
        }
    }
    cout << dp[m - 1][n];
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}