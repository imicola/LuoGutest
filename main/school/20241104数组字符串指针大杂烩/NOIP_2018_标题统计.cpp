#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    int ans = 0;
    for (auto &&i : s) {
        if (i != '\r\n' && i != ' ' && i != '\n') ans++;
    }
    cout << ans;
    return 0;
}