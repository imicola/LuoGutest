/*
    P1044递推解法
    注意到待入栈数n里的第k个数: 设其方案有f[k] (k > 0)
    则 k 前面的数的排列方式有 f[k-1] 种
    k 后面的数的排列方式有 f[n-k]种
    根据组合数原理: f[k] = f[k-1] * f[n-k]
    则有  f[n] = sum_{k = 0}^{n-1} f[k] 即 f[n] = f[0]f[n-1] + f[1]f[n-2] ...... + f[n-1]f[0]
    简单分析不难发现f[0] = 1 , f[1] = 1, f[2] = 2;
*/

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    long long f[20] = {1, 1, 2};
    cin >> n;
    // 在这里 i 表示上文的 n ; j 表示上文的 k;
    // 因为f[0] , f[1] , f[2] 均已明确 i 从 3 开始算;
    for (size_t i = 3; i <= n; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            f[i] += f[j - 1] * f[i - j];
        }
    }
    cout << f[n];
    return 0;
}