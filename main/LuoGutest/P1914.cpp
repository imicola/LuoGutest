#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] + n > (int)'z')
        {
            s[i] = 'a' + (s[i] + n) - 'z' - 1;
        }
        else
        {
            s[i] = s[i] + n;
        }
    }
    cout << s;
}