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
    string s;
    cin >> n >> s;
    vint dp(1 << n, 0);
    dp[0] = 1;
    for (size_t i = 0; i < (1 << n); i++) {
        if (!dp[i]) {
            continue;
        }
        for (size_t j = 0; j < n; j++) {
            if (i & (1 << j)) {
                continue;
            }
            int nxt = (i | (1 << j));
            if (s[nxt - 1] == '0') {
                dp[nxt] = 1;
            }
        }
    }
    cout << (dp[(1 << n) - 1] ? "Yes" : "No") << endl;
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