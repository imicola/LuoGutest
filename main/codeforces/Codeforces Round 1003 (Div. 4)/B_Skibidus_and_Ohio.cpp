//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
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
    int cnt = s.size();
    for (size_t i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cnt = 1;
        }
    }
    cout << cnt << endl;
}
// addca -> 1
// nbbjkds -> 1
// ptojj -> 1

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}