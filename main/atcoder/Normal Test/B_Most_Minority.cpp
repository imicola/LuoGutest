//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            char c;
            cin >> c;
            mp[i][j] = (c - '0');
        }
    }
    map<i64, i64> ans;
    i64 maxx = INT_MIN;
    for (size_t i = 0; i < m; i++) {
        int cnt = 0;
        for (size_t j = 0; j < n; j++) {
            cnt += mp[j][i];
        }
        if (cnt == 0 || cnt == n) {
            for (size_t k = 0; k < n; k++) {
                ans[k]++;
                maxx = max(maxx, ans[k]);
            }
        }
        else {
            int p = (cnt > n / 2 ? 1 : 0);
            for (size_t k = 0; k < n; k++) {
                ans[k] += (mp[k][i] == p ? 0 : 1);
                maxx = max(maxx, ans[k]);
            }
        }
    }
    for (auto &&i : ans) {
        if (i.second == maxx) cout << i.first + 1 << " ";
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}