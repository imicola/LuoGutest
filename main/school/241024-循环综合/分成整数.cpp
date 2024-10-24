#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

//函数，用于判断该数是否含有 3 或 7
bool ishave(int i)
{
    //判断该数是否含有 3 或 7
    if(i%10 == 3 || i%10 == 7 || (i/10)%10 == 3 || (i/10)%10 == 7 || i/100 == 3)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    int flag = 0;
    cin >> n;
    //遍历所有可能的组合
    for (size_t i = 1; i < n; i++)
    {
        //如果该数含有 3 或 7，则跳过
        if(ishave(i)) continue;
        for (size_t j = i+1 ; j < n; j++)
        {
            //如果该数含有 3 或 7，则跳过
            if (ishave(j)) continue;
            for (size_t k = j+1; k < n; k++)
            {
                //如果该数含有 3 或 7，则跳过
                if(ishave(k)) continue;
                //如果三个数的和等于 n，则计数器加 1
                if(k + j + i == n)
                {
                    flag++;
                   //cout << i << j << k<<endl;
                }
            }
        }
    }
    //输出计数器的值
    cout << flag;
    return 0;
}