//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    vector<int> maps(s.size());
    string ans;
    vector<string> temp;
    int k = 1;
    int p = 1;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == '[') {
            maps[distance(s.begin(), it)] = k++;
        }
        p = k;
        if (*it == ']') {
            maps[distance(s.begin(), it)] = --p;
        }
    }
    for (auto &&i : maps)
    {
        cout << i;
    }
    
    
    
    return 0;
}