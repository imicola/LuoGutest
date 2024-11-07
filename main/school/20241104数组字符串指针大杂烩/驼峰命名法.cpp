//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    // int add = 0;
    // int p = 0;
    for (auto it = s.begin();it < s.end() ; it++) {
        if (*it >= 'A' && *it <= 'Z') {
            *it = *it - 'A' + 'a';
            if (it > s.begin()) {
                it = s.insert(it, ' ');
            }
        }
    }
    cout << s;
    return 0;
}