#include <bits/stdc++.h>
using namespace std;

// 全局变量定义
int n,m,p;
int arr[120][120];

// 主函数，程序入口
int main()
{
    cin >> n >> m >> p;

    // 处理火把的位置
    for (size_t i = 0; i < m ; i++)
    {
        int tempx = 0,tempy = 0;
        cin >> tempx >> tempy;
        tempx +=2;
        tempy +=2;
        //火把判定
        for (size_t k = tempy - 1; k <= tempy + 1; k++)
        {
            for (size_t j = tempx - 1; j <= tempx + 1; j++)
            {
                arr[k][j] = 1;
            }
        }
        arr[tempy+2][tempx] = 1;
        arr[tempy-2][tempx] = 1;
        arr[tempy][tempx+2] = 1;
        arr[tempy][tempx-2] = 1;
    }
    //计算荧石
    for ( int i = 0; i < p; i++)
    {
        int tempx,tempy;
        cin >> tempx >> tempy;
        tempx +=2;
        tempy +=2;
        for (size_t k = tempy - 2; k <= tempy + 2; k++)
        {
            for (size_t j = tempx - 2; j <= tempx + 2; j++)
            {
                arr[k][j] = 1;
            }
        }
    }
    //计算未照明数量
    int sum = 0;
    for (size_t i = 3; i <= n+2 ; i++)
    {
        for (size_t k = 3; k <= n+2 ; k++)
        {
            //cout <<setw(3)<< arr[i][k] << " ";
            if (arr[i][k] == 0 )
            {
                sum++;
            }
        }
        //cout << endl;
    }
    cout <<sum;

    return 0;
    //鸡毛入门题
}