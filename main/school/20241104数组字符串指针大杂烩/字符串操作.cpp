#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (size_t i = 0; i < m; i++) {
        int a, b;
        char c1, c2;
        cin >> a >> b >> c1 >> c2;
        for (size_t j = a - 1; j < b; j++) {
            if (s[j] == c1) s[j] = c2;
        }
    }
    cout << s;
    return 0;
}