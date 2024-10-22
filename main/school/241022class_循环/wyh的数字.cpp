#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int flag = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '7')
            {
                flag++;    
            }
        }
        cout << flag <<endl;
    }
    
    return 0;
}