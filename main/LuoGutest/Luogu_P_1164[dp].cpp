//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 10);
    for (size_t i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (j < arr[i]) dp[i][j] = dp[i - 1][j];
            if (j == arr[i]) dp[i][j] = dp[i - 1][j] + 1;
            if (j > arr[i]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
        }
    }
    cout << dp[n][m];
    return 0;
}

// i 表示选择的是前i道菜
// j 表示花费的钱
// j > arr[i] 情况下
// dp[i][j] 表示的是在选择i道菜的前提下完全花光 j 元所有的情况类型数
// 当考虑到第 i 种菜的价格 p[i] 时，针对当前预算 j 有以下几种情况：
// 不选第 i 道菜：
// 如果不选第 i 种菜，那么方案数应与使用前 [ i - 1 ]道菜时的方案数相同，即 cell[i][j] = cell[i - 1][j]。
// 选择第 i 道菜：
// 如果选择了第 i 道菜，那么剩余预算应当减少 p[i]，即 j - p[i]。 在这种情况下，方案数应等于在预算为 j - p[i]、只使用前 i - 1 道菜时的方案数，即 cell[i][j - p[i]]