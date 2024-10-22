#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    int k = 1;
    cin >> n;
    for (size_t i = n; i > 0; i--)
    {
        for (size_t j = 1; j <= n+k; j++)
        {
            if (j < i)
            {
                cout<<" ";
                continue;
            }
            if ((j+i)%2 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout <<endl;
        k+=1;
    }
    
    return 0;
}