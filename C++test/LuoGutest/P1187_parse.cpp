#include <bits/stdc++.h>
using namespace std;

int city[1010][1010] = {0};

//思路：对立方体图，可以这样切入 ==> (俯视图 + 正视图 + 侧视图 + 凹槽)*2
//俯视图思路简单：扫一遍全图，只要不为0就++;
//正视图 ==> 以每一列位单位，向后扫高度，如果或一个比前一个高，就加上这两个的差值，如果低的话就不用加
//侧视图与正视图同理，但是以每一行位单位
//最后把sum相加乘2就行了
//下面代码注释由ai生成，请注意鉴别

// 主函数，程序入口
int main()
{
    // 初始化变量 m 和 n
    int m = 0,n = 0;
    int lin = 0;
    // 从输入读取 n 和 m 的值
    cin >> n >> m;
    // 循环读取 n 行城市数据
    for (size_t i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        // 更新 city 数组中的每个城市数据
        for (size_t k = 1; k <= m; k++)
        {
            city[i][k] += s[k - 1] - '0';
        }
    }
    // 此部分原代码为注释，可能用于输出 city 状态
    // int sum = 0; 
    //     for (size_t i = 1; i <= m ; i++)
    //     {
    //         for (size_t k = 1; k <= n; k++)
    //         {
    //             cout << city[i][k];
    //         }
    //         cout << endl;
    //     }
    // 用于计算城市中非零元素的总和
    int sum = 0;
    // 计算城市中所有非零元素
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t k = 1; k <= m; k++)
        {
            if (city[i][k])
            {
                sum++;
            }
        }
    }
    // 计算相邻城市之间的差异
    for (size_t i = 1; i <= m; i++)
    {
        for (size_t k = 1; k <= n; k++)
        {
            if (city[k][i] > city[k-1][i])
            {
                sum += city[k][i] - city[k - 1][i];
            }
        }
    }
    // 计算同一行中相邻城市间的差异
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t k = 1; k <= m; k++)
        {
            if (city[i][k] > city[i][k - 1])
            {
                sum += city[i][k] - city[i][k - 1];
            }
        }
    }
    // 输出最终结果，乘以 2
    cout << sum*2;
 
    return 0;
    
}