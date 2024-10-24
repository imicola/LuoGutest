#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    // 定义变量n，flag，x，y，z，m，m初始化为0
    double n,flag = 0,x,y,z,m = 0;
    // 输入x，y，z，n，m的值
    cin >> x >> y >> z >> n >> m;
    // 遍历i，j，k的值
    for (size_t i = 0; i <= n / x; i++)
    {
        for (size_t j = 0; j <= (n - x * i) / y; j++)
        {
            // 计算k的值
            size_t k = m - i - j;
            // 判断x * i + y * j + (k / z)是否等于n，并且i + j + k是否等于m
            if (x * i + y * j + (k / z) == n)
            {
                // 如果满足条件，flag加1
                flag++;
            }
        }
    }
    // 输出flag的值
    cout << flag;
    
    return 0;
}
