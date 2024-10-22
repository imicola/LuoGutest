#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            cout << i <<" ";
        }
        cout << endl;
    }
    
    return 0;
}