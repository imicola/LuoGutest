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

// 记忆化递归
// 状态定义：dp[a][n][last_num] 表示用 n 个数来构成 a，且每个数都大于等于 last_num。
// men就是用于存放递归状态的数组
// 对于 result --> 其表示在当前状态下的可划分数量，我们将result赋值给men 用于存放当前状态的数的情况
int men[21000][610][21000];
int f(int a, int n, int last_num)
{
    if (n == 0 && a == 0)
        return 1;
    if (n <= 0 || a < 0)
        return 0;
    if (men[a][n][last_num] != -1) return men[a][n][last_num];
    int result = 0;
    for (size_t i = last_num; i <= a; i++) {
        result += f(a - i, n - 1, i);
    }
    men[a][n][last_num] = result;
    return men[a][n][last_num];
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, n;
    cin >> a >> n;
    memset(men, -1, sizeof(men));
    cout << f(a, n, 1);
    return 0;
}