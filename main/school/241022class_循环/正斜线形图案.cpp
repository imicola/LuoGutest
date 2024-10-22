#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = n; i > 0; i--)
    {
        for (size_t k = 1; k < i; k++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }
    
    return 0;
}
   