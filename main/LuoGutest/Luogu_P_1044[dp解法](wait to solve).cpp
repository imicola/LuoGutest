#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    // 定义二维数组dp i表示队列里剩下多少个待排的数，j表示栈里有多少个数
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][n];
    return 0;
}