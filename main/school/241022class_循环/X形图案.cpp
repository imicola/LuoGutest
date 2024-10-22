#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if (j == i||j == n - i + 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    
    return 0;
}