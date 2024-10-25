#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool ele(int a)
{
    string s = to_string(a);
    if (s.find('7') != string::npos || a%7 == 0) return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    int flag = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if(!ele(i)) flag++; 
    }
    cout << flag;
    return 0;
}