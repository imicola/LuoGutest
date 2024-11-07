//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (!isalpha(s[i])) ans++;
    }
    cout << ans;
    return 0;
}