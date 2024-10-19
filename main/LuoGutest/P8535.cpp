#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    string s;
    if (n % 5 == 0)
    {
        for (size_t i = 0; i < n/5; i++)
        {
            s += "1";
        }
    }
    else
    {
        if (n%5 >= 3)
        {
            s += "2";
            for (size_t i = 0; i < n/5 - 1; i++)
            {
                s += "1";
            }
        }
        else
        {
            for (size_t i = 0; i < n/5 ; i++)
            {
                s += "1";
            }
        }
    }
    
    cout << s;
    return 0;
}