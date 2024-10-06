#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int len=s.size()-1;
    if(s[len]==13)
    {
        len--;
    }
    int n;
    int x = -1;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        x += a;
        if (x >= len)
        {
            x = len;
            continue;
        }
        if (s[x] == '>' )
        {
            int temp1 = 0;
            for (size_t j = x; j <= len; j++)
            {
                if (s[j] == '>')
                {
                    temp1++;
                }
                else
                {
                    break;
                }
            }
            if (temp1 > 2)
            {
                x += temp1;
            }
            
            if (x > len)
            {
                x = len;
            }
            continue;
        }
        if (s[x] == '*' )
        {
            int temp1 = 0;
            for (size_t j = x; j <= len; j++)
            {
                if (s[j] == '*')
                {
                    temp1++;
                }
                else
                {
                    break;
                }
            }

            if (temp1 > 2)
            {
                x -= temp1;
            }

            if (x < 0)
            {
                x = 0;
            }
            continue;
        }
    }
    cout << x+1 << " " << len - x;
    return 0;
}