#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,flag = 0;
    cin >> n;
    for (int i = n; i >= 0; i-=5)
    {
        for (int p = i;p >= 0; p-=2)
        {
            for (int k = p;k >= 0; k--)
            {
                if (k == 0)
                {
                    flag++;
                    break;
                }
            }
        }
    }
    cout << flag;
    
    return 0;
}