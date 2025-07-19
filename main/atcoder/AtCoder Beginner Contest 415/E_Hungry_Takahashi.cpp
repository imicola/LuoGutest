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
    int h, w;
    cin >> h >> w;
    vvint mp(h, vint(w));
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++) {
            cin >> mp[i][j];
        }
    }
    vint p(h + w - 1, 0);
    for (size_t i = 0; i < h + w - 1; i++) {
        cin >> p[i];
    }
    vvint dp(h, vint(w, LLONG_MAX));
    dp[h - 1][w - 1] = max(0ll, p[h + w - 2] - mp[h - 1][w - 1]);
    for (int i = w - 2; i >= 0; i--) {
        dp[h - 1][i] = max(0ll, dp[h - 1][i + 1] + p[h + i - 1] - mp[h - 1][i]);
    }
    for (int i = h - 2; i >= 0; i--) {
        dp[i][w - 1] = max(0ll, dp[i + 1][w - 1] + p[w + i - 1] - mp[i][w - 1]);
    }
    for (int i = h - 2; i >= 0; i--) {
        for (int j = w - 2; j >= 0; j--) {
            int k1 = max(0ll, dp[i + 1][j] + p[i + j] - mp[i][j]);
            int k2 = max(0ll, dp[i][j + 1] + p[i + j] - mp[i][j]);
            dp[i][j] = min(k1, k2);
        }
    }
    cout << dp[0][0] << endl;
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