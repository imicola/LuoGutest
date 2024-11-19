#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'V' && s[i + 1] == 'K') {
            s[i] = '0';
            s[i + 1] = '0';
            ans++;
        }
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        if ((*i == 'V' && *(i + 1) == 'V') || ((*i == 'K' && *(i + 1) == 'K'))) {
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}