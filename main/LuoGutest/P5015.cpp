#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    string s;
    int ans = 0;
    getline(cin,s);
    for(auto &&i :s)
    {
        if (i <= 'z' && i >= 'a')
        {
            ans++;
        }
        else if (i >= 'A' && i <= 'Z')
        {
            ans++;
        }
        else if (i >= '0' && i <= '9')
        {
            ans++;
        }        
    }
    cout << ans;


    return 0;
}