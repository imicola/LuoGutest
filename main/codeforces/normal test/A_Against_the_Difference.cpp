//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
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
    int n;
    cin >> n;
    vint a(n + 1);
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // dp[i] 表示idx = i 时候前面可构造序列的最长长度
    // 初始化？ 显然都为 0
    // 转移方程？
    // 可以选择是否加入dp[i]
    // 如果不加入dp[i] , 则有 dp[i] = dp[i - 1]
    // 如果选择加入 dp[i]
    // 这意味着我们必须从当前位置向前找到计数数目减去a[i]的元素然后用其坐标x下的dp[x] + a[i] 来更新dp[i]
    // 什么时候可以将a[i]加入dp？即当计数数目等于a[i]时候
    vint dp(n + 1, 0);
    map<int, deque<int>> re;
    // re[a[i]] 为 元素 a[i] 下标构成的集合
    for (size_t i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        re[a[i]].emplace_back(i);
        if (re[a[i]].size() > a[i]) {
            re[a[i]].pop_front();
        }
        if (re[a[i]].size() == a[i]) {
            dp[i] = max(dp[i], dp[re[a[i]].front() - 1] + a[i]);
        }
    }
    cout << dp[n] << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}