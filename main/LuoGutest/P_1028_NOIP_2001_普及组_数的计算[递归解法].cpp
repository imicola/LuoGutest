//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//n表示数列末尾的数
int f(int n)
{
    //边界情况 --> 当数列末尾的数为1是直接返回1
    if (n == 1) return 1;
    //某一个数列情况的总和
    int result = 0;
    //从单数列 1 开始寻找小于 n/2 的数列子集个数并加和
    for (size_t i = 1; i <= n / 2; i++) {
        result += f(i);
    }
    //返回值要加上 n 本身
    return result + 1;
}

/*
逻辑详解: 
    对 n = 6 时 n/2 = 3
    有  f(6) = f(3) + f(2) + f(1) + 1;  (1)
        f(3) = f(1) + 1;
        f(2) = f(1) + 1;
        f(1) = 1;
        则累计为
    f(6) = 2+2+1+1 = 6
        why (1) 是这么写的？
    通项:f(n) = f(n/2) + f(n/2 - 1) + f(n/2 - 2) ...... +f(1)
    --> 算数学归纳法?
    我们可以这样理解:
    对 n 而言，构造所有符合题意的数列即为 --> 构造对任意 k(k <= n/2 && k > 0) 的符合题意的所有数列 + n本身
    回到 6
    对 6 而言 ： 可构造的数列为 a3 a2 a1 6
    a3 = {3,3 1};
    a2 = {2,2 1};
    a1 = {1};

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}