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
    vpii v(n);
    map<i64, map<i64, i64>> mp;
    map<i64, vint> X, Y;
    for (i64 i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;
        v[i] = {x, y};
        mp[x][y] = 1;
        X[x].emplace_back(y);
        Y[y].emplace_back(x);
    }
    map<i64, i64> cnt1, cnt2;
    for (auto &&[u, v] : X) {
        for (auto &&vv : v) {
            if (mp[u + 1][vv]) cnt1[u]++;
        }
    }
    for (auto &&[u, v] : Y) {
        for (auto &&vv : v) {
            if (mp[vv][u + 1]) cnt2[u]++;
        }
    }
    i64 ans = 0;
    for (auto &&[_, v] : cnt1) ans += v * (v - 1) / 2;
    for (auto &&[_, v] : cnt2) ans += v * (v - 1) / 2;
    for (auto &&[x, y] : v) {
        if (mp[x + 1][y] && mp[x][y + 1] && mp[x + 1][y + 1]) ans--;
    }
    cout << ans << endl;
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