//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    string o = "";
    bool flag = 0;
    if (s[0] >= 'a')
        o += (s[0] - 'a' + 'A');
    else
        o += s[0];
    for (auto &&i : s) {
        if (i == ' ') {
            flag = 1;
            continue;
        }
        if (flag && i != ' ') {
            if (i >= 'a')
                o += (i - 'a' + 'A');
            else
                o += i;
            flag = 0;
        }
    }
    cout << o;
    return 0;
}