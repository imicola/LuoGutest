//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    string s;
    cin >> s;
    pii p = {0, 0};
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (p.first == 0) {
                p.first = i + 1;
                continue;
            }
            else
                p.second = i + 1;
            
            if (p.second != 0) {
                cout << p.first << "," << p.second << endl;
                p = {0, 0};
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}