// LIS DP模板题
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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vint v(t);
    for (auto &&i : v) {
        cin >> i;
    }
    vint dp(t, 1); // 表示到 i 的时候最大的上升子序列的长度
    int ans = 1;
    for (size_t i = 0; i < t; i++) {
        for (size_t j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    // 开二重循环，第一重表示到数 a_i ，第二重从 0 —— a_(i-1) , 只要 a_j < a_i
    // 就表示这个a_j 可以被拉入上升序列里 此时去 dp[i] = max(dp[i] , dp[j] + 1)
    cout << ans;
    return 0;
}