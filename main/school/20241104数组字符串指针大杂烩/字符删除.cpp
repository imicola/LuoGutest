//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    char p;
    cin >> s >> p;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == p) s[i] = '|';
    }
    int ans = 0;
    for (auto &&i : s) {
        if (i == '|') {
            ans++;
        }else
            cout << i;
    }
    cout << endl << s.size() - ans;

    return 0;
}