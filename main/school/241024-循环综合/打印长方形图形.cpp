#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int a;
    cin >> a;
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < a; j++)
        {
            if (i == 0 || i == a-1)
            {
                cout <<"*";
            }
            else
            {
                if (j == 0 || j == a - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << "+";
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}