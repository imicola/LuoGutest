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
    vpii vp(n);
    for (auto &&[i, j] : vp) cin >> i;
    for (auto &&[i, j] : vp) cin >> j;
    // i 数量 ，j 营养
    sort(all(vp), [](pii a, pii b) { return a.second < b.second; });
    i64 q;
    cin >> q;
    vint pnum(n);
    // 单一营养价值前缀
    pnum[0] = vp[0].first;
    for (i64 i = 1; i < n; i++) {
        pnum[i] = pnum[i - 1] + vp[i].first;
    }
    vint psum(n);
    // 营养和前缀
    psum[0] = vp[0].first * vp[0].second;
    for (i64 i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + vp[i].first * vp[i].second;
    }
    while (q--) {
        i64 k;
        cin >> k;
        i64 ans = 0;
        auto _idx = upper_bound(all(vp), k, [](i64 k, pii a) { return k < a.second; });
        if (_idx == vp.end()) {
            cout << psum[n - 1] << endl;
            continue;
        }
        i64 idx = _idx - begin(vp);
        if (idx == 0) {
            cout << k*pnum[n - 1] << endl;
        }
        else {
            cout << psum[idx - 1] + k * (pnum[n - 1] - pnum[idx - 1]) << endl;
        }
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