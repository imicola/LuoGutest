//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, m;
    cin >> t >> m;
    vector<int> time(m);
    vector<int> val(m);
    for (size_t i = 0; i < m; i++) {
        cin >> time[i] >> val[i];
    }
    vector<vector<int>> dp(m, vector<int>(t + 1, 0));
    // dp[i][j] 表示任取 0 ~ i 个草药所j时间下取得的val最大值
    for (size_t i = time[0]; i <= t; i++) {
        dp[0][i] = val[0];
    }
    //第0行
    //第0列
    for (size_t i = 1; i < m; i++) {
        for (size_t j = 1; j <= t; j++) {
            if (j < time[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + val[i]);
        }
    }
    cout << dp[m - 1][t];
    return 0;
}