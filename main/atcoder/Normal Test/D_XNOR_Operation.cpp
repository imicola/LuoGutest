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
    string s;
    cin >> s;
    s = " " + s;
    vvint dp(n + 1, vint(2));
    for (size_t i = 1; i <= n; i++) {
        dp[i][s[i] - '0'] = 1;
    }
    // dp[i][j] 表示在第i个位置凑出j的方案数
    for (size_t i = 2; i <= n; i++) {
        if (s[i] == '1') {
            dp[i][0] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][1];
        }
        else {
            dp[i][0] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][0];
        }
    }
    int ans = 0;
    for (size_t i = 1; i <= n; i++) {
        ans += dp[i][1];
    }
    cout << ans << endl;
}
/*
    一个串满足什么条件时候我们可以认定其可以变化为1
    本身就是 1
    偶数个连续的 0/1
    
    ? 是否为dp
    后一个能不能由前面决定
    当我们 S -> -00 -> +1时候 0 -= 2 ，1 += 1
    当我们 S -> -01 -> +0时候 0 -= 0 ，1 -= 1
    当我们 S -> -10 -> +0时候 0 -= 0 ，1 -= 1
    当我们 S -> -11 -> +1时候 0 -= 0 ，1 -= 1
    我们需要的是把0的数量变为0
    故只有第一种符合需求
    我们发现其他的都不会对0的数量产生影响
    所以一开始能不能变成 1 依靠开始 0 的奇偶性
    则我们判断后一个加入进来会不会对奇偶性造成影响

*/
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}