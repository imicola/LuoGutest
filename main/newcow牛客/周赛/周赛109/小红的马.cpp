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
    i64 n;
    cin >> n;
    map<pii, i64> mp;
    map<pii, i64> have;
    pii ans = {0, 0};
    vint x0 = {2, 2, 1, 1, -2, -2, -1, -1}, y0 = {1, -1, 2, -2, 1, -1, 2, -2};
    for (i64 i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;
        have[{x, y}]++;
        for (i64 k = 0; k < 8; k++) {
            i64 ax = x + x0[k];
            i64 ay = y + y0[k];
            if (ax > 0 && ay > 0) {
                mp[{ax, ay}]++;
            }
        }
    }
    vector<pair<pair<i64,i64>,i64>> res(all(mp));
    sort(all(res), [](auto a, auto b) { return a.second > b.second; });
    for (auto &&[key, val] : res) {
        if (have.contains(key)) continue;
        cout << key.first << " " << key.second;
        return;
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