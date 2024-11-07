//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    for (auto it = s.begin(); it < s.end(); it++) {
        int flag = 0;
        while (*it == ' ') {
            s.erase(it);
            flag = 1;
        }
        if (flag) {
            it = s.insert(it, ' ');
            flag = 0;
        }
    }
    cout << s;
    return 0;
}