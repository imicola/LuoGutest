#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    for (int i = 1; i < 10; i++) // i 代表 行
    {
        for (int j = 1; j < i+1 ; j++) // j 代表 列 
        {
            printf("%d*%d=%2d ",j,i,i*j);
        }
        cout << endl;
    }   
    return 0;
}