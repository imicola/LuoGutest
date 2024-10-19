#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long k = 0;
    string s1 = "Iloveyou";
    for (size_t i = 0; i < s.size(); i++)
    {
        string temp = s.substr(i,8);
        if (temp == s1)
        {
            k += 8;
            i += 7;
        }
    }
    cout << k%20010905;
}