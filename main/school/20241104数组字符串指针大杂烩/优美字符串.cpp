#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string s;
        int ans = 0;
        cin >> s;
        for (size_t j = 0; j < s.size() - 1; j++) {
            if (s[j] == s[j + 1]) ans++;
        }
        cout << s.size() + ans << endl;
    }

    return 0;
} 