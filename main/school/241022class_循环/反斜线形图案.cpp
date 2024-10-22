#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = 0; k < i; k++)
        {
            cout << " ";
        }
        cout << "*"<<endl;
    }
    
    return 0;
}