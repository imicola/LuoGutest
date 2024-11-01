#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (size_t i = 0; i < s1.size(); i++) {
        for (size_t k = 0; k < s2.size(); k++) {
            if (s1[i] == s2[k]) {
                s1[i] = '|';
            }
        }
        if (s1[i] == '|') continue;
        else cout << s1[i];
    }

    return 0;
}