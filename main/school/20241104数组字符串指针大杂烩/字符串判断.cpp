#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1;
    string s2;
    cin >> s1 >> s2;
    for (auto &&i : s2)
    {
        if(s1.find(i) != string::npos){
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
    return 0;
}