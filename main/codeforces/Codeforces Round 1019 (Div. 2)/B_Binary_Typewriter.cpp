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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = "0" + s;
    int cnt01 = 0, cnt10 = 0;
    bool ok = 0;
    for (size_t i = 0; i + 1 < s1.size(); i++) {
        if (s1[i] != s1[i + 1] && s1[i] == '0') cnt01++;
        if (s1[i] != s1[i + 1] && s1[i] == '1') cnt10++;
    }
    cout << n + cnt01 + cnt10 - (cnt01 + cnt10 > 1 ? (cnt01 >= 2 || cnt01 >= 2 ? 2 : 1) : 0) << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}