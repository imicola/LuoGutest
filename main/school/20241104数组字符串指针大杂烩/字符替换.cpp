#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    char a, b;
    cin >> a >> b;
    for (auto &&i : s) {
        if (i == a)
            cout << b;
        else
            cout << i;
    }

    return 0;
}