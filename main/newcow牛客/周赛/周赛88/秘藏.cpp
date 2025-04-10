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
    int n, k;
    cin >> n >> k;
    vvint v(2, vint(n + 1));
    int check = 0;
    for (size_t i = 1; i <= n; i++) {
        int temp = 0;
        cin >> v[0][i];
        check += v[0][i];
    }
    for (size_t i = 1; i <= n; i++) {
        cin >> v[1][i];
    }
    if (check <= k) {
        cout << check;
        return;
    }
    vvint dp(n + 1, vint(2,INT_MIN)); // 当前金币的持有数量 i -> index j -> 世界
    dp[1][0] = v[0][1];
    dp[1][1] = INT_MIN;
    int ans = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[i][j] == INT_MIN) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[j][i + 1]);
            if (dp[i][j] >= k) dp[i + 1][1 - j] = max(dp[i + 1][1 - j], dp[i][j] - k + v[1 - j][i + 1]);
        }
    }
    cout << max(dp[n][0], dp[n][1]);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}