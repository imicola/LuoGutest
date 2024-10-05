#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string ste;
    cin >> s;
    string s1 = s;
    int k;
    s += s.back();
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i+1]&&s[i] == s[i-1])
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                i++;
            }
            else
            {
                s[i] = '0';
                i++;
            }
        }
    }

    for (size_t i = 0; i < s1.size(); i++)
    {
            if (s[i] == '0')
            {
                ste.push_back('1') ;
            }
            else
            {
                ste.push_back('0');
            }
    }
    // cout << s<<endl;
    // cout << s1<<endl;
    // cout << ste;
    int p1 = 0;
    int p2 = 0;
    for (size_t i = 0; i < s.size()-1; i++)
    {
        if (s[i] != s1[i])
        {
            p1 += i+1;
        }

        if (ste[i] != s1[i])
        {
            p2 += i+1;
        }
    }
    cout <<min(p1,p2);
}