#include <bits/stdc++.h>
using namespace std;

// 主函数，程序入口
int main()
{
    double a; // 输入的金额
    int b,c,d; // 输入的月份和其他控制变量
    cin >> a >> b >> c >>d; // 读取输入值
    if ((b == c && b == 11 ))
    {
        a *= 0.7; // 处理11月的折扣
        if (d)
        {
            a -= 50; // 如果满足条件，进一步减少50
        }
    }
    else if ((b == c && b == 12))
    {
        a *= 0.8; // 处理12月的折扣
        if (d)
        {
            a -= 50; // 如果满足条件，进一步减少50
        }
    }
    
    if (a < 0)
    {
        cout << "0.00"; // 输出金额为负时的处理
    }
    else
    {
        printf("%.2f",a); // 输出处理后的金额
    }
       
}