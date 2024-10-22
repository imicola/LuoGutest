#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i==0||i == n-1)
            {
                cout << "*"<<" ";
            }
            else
            {
                if (j == 0 || j == n-1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }           
        }
        cout << endl;
    }
    
    return 0;
}