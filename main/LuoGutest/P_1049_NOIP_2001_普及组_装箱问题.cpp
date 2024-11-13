//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v, n;
    cin >> v >> n;
    vector<int> p(n);
    for (size_t i = 0; i < n; i++) {
        cin >> p[i];
    }
    // p[i] 是第i个物品的重量 和 价值
    vector<vector<int>> dp(n, vector<int>(v + 1, 0));
    // dp[i][j] : 从0号到i号任取 背包容量为j 的最大容量
    // dp[0][i] :
    for (int i = p[0]; i <= v; i++) {
        dp[0][i] = p[0];
    }
    for (int i = 1; i < n;i++)
    {
        // 遍历物品
        for (int j = 1; j <= v ;j++)
        {
            if (j - p[i] < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], p[i] + dp[i - 1][j - p[i]]);
        } 
    }
    cout << v - dp[n - 1][v];
}