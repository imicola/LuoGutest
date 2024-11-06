#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    int ans = 0, pos1 = 0, pos2 = 0;
    while ((pos1 = s.find("v", pos1)) != string::npos) {
        ans++;
        pos1 += 1;
    }
    while ((pos2 = s.find("V", pos2)) != string::npos) {
        ans++;
        pos2 += 1;
    }
    if (ans == 0)
        cout << 0 << " " << -1;
    else
        cout << ans << " " << min(s.find_first_of('V'), s.find_first_of('v'));
    return 0;
}