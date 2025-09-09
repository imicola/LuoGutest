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
    i64 s, b;
    cin >> s >> b;
    vint at(s);
    for (auto &&i : at) cin >> i;
    vector<pair<i64, i64>> vp(b);
    for (auto &&[i, j] : vp) {
        cin >> i >> j;
    }
    ranges::sort(vp, [](auto a, auto b) { return a.first < b.first; });
    vint ans(s);
    vint preval(b);
    preval[0] = vp[0].second;
    for (i64 i = 1; i < b; i++) {
        preval[i] = preval[i - 1] + vp[i].second;
    }
    auto check = [&](i64 atc, i64 mid) -> bool { return atc >= vp[mid].first; };
    for (i64 i = 0; i < s; i++) {
        i64 l = 0, r = b - 1, idx = 0;
        if (at[i] < vp[0].first) {
            ans[i] = 0;
            continue;
        }
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (check(at[i], mid)) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        // cout << r << endl;

        ans[i] = preval[idx];
    }
    for (auto &&i : ans) {
        cout << i << " ";
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