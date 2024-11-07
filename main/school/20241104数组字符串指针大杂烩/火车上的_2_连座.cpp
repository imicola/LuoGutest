//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while (cin >> n) {
        int flag = 0;
        vector<string> s(n, string(5, '0'));
        for (size_t i = 0; i < n; i++) {
            cin >> s[i];
        }
        for (size_t i = 0; i < n; i++) {
            if ((s[i][0] == s[i][1] && s[i][1] == 'O') || (s[i][3] == s[i][4] && s[i][3] == 'O')) {
                cout << "YES" << endl;
                if (s[i][0] == s[i][1] && s[i][1] == 'O') {
                    s[i][0] = '+';
                    s[i][1] = '+';
                }
                else {
                    s[i][3] = '+';
                    s[i][4] = '+';
                }
                for (auto &&i : s) {
                    cout << i << endl;
                }
                flag++;
                break;
            }
        }
        if (flag == 0) cout << "NO" << endl;
    }
    return 0;
}