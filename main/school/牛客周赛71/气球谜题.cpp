#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string colors;
    cin >> colors;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(3, 1e18)); // 初始化为一个很大的值
    for (int c = 0; c < 3; c++) {
        dp[0][c] = (colors[0] - '0' == c) ? 0 : t[0];
    }
    for (int i = 1; i < n; i++) {
        for (int c = 0; c < 3; c++) {
            if (colors[i] - '0' == c) {
                dp[i][c] = min(dp[i][c], dp[i - 1][c]); // 不染色
            }
            else {
                dp[i][c] = min(dp[i][c], dp[i - 1][c] + t[i]); // 染成c的颜色
            }
        }
        for (int c = 0; c < 3; c++) {
            for (int prev_color = 0; prev_color < 3; prev_color++) {
                if (c != prev_color) {
                    dp[i][c] = min(dp[i][c], dp[i - 1][prev_color] + t[i]);
                }
            }
        }
    }
    long long result = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << result << endl;

    return 0;
}
