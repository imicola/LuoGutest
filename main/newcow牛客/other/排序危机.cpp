#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string k1, k2, k3;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            k1 += s[i];
        else if (s[i] >= 'A' && s[i] <= 'Z')
            k2 += s[i];
        else
            k3 += s[i];
    }
    cout << k1 + k3 + k2;
    return 0;
}