//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int strcount(string s, char ch)
{
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ch) ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    getline(cin, mp[0]);
    mp[0] = "";
    for (size_t i = 0; i < n; i++) {
        // cin >> mp[i];
        getline(cin, mp[i]);
    }
    for (size_t i = 0; i < n; i++) {
        int a1 = 0, b1 = 0, h1 = 0;
        a1 = strcount(mp[i], 'A');
        b1 = strcount(mp[i], 'B');
        if (mp[i].find('H') != string::npos) {
            h1 = mp[i].find('H');
            for (size_t j = 0; j < m; j++) {
                mp[i][j] = '#';
            }
            for (size_t j = 0; j < a1; j++) {
                mp[i][j] = 'A';
            }
            for (size_t j = 0; j < b1; j++) {
                mp[i][m - j - 1] = 'B';
            }
            mp[i][h1] = 'H';
        }
        else {
            if (a1 > b1) {
                for (size_t j = 0; j < m; j++) {
                    mp[i][j] = '#';
                }
                for (size_t j = 0; j < a1; j++) {
                    mp[i][m - j - 1] = 'A';
                }
            }
            else if (b1 > a1) {
                for (size_t j = 0; j < m; j++) {
                    mp[i][j] = '#';
                }
                for (size_t j = 0; j < b1; j++) {
                    mp[i][j] = 'B';
                }
            }
            else if (a1 == b1) {
                for (size_t j = 0; j < m; j++) {
                    mp[i][j] = '#';
                }
            }
        }
    }
    for (size_t i = 1; i < n - 1; i++) {
        for (size_t j = 0; j < m; j++) {
            if ((mp[i][j] == mp[i - 1][j] || mp[i][j] == mp[i + 1][j]) && (mp[i][j] != '#' && mp[i][j] != 'H')) {
                if (mp[i][j] == mp[i - 1][j] && mp[i][j] == mp[i + 1][j]) {
                    mp[i + 1][j] = '#';
                    mp[i - 1][j] = '#';
                }
                else if (mp[i][j] == mp[i - 1][j])
                    mp[i - 1][j] = '#';
                else if (mp[i][j] == mp[i + 1][j])
                    mp[i + 1][j] = '#';
                mp[i][j] = '#';
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        cout << mp[i] << endl;
    }
    return 0;
}