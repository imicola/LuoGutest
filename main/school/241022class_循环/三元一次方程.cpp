#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int flag = 0;
    for (int i = -30 ; i <= 30; i++)
    {
        for (int k = -30; k <= 30; k++)
        {
            for (int p = -30; p <= 30; p++)
            {
                if (2*i + 3*k + 5*p == 100)
                {
                    flag++;
                }
                
            }
            
        }
        
    }
    cout << flag;   
    return 0;
}