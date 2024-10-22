#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    for (size_t i = 0; i < 1e4; i++)
    {
        for (size_t j = 0; j < 1e4; j++)
        {
            if (2*i+4*j == m && i+j == n)
            {
                cout << i <<" "<<j;
                return 0;
            }
        }
    }
    cout << "No answer!";
    
    return 0;
}