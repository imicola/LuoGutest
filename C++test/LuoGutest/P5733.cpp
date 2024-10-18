#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - (int)('a' - 'A');
        }
    }
    cout << s;
}