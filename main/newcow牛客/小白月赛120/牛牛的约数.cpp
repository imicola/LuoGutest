#pragma GCC optimize(3)
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
    vint a(n);
    vector<pair<i64, i64>> vp(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
        vp[i] = {a[i], i};
    }
    ranges::sort(vp, [](auto a, auto b) { return a.first < b.first; });
    vector<pair<i64, i64>> path;
    vint ans(n, -1);
    for (auto &&[i, idx] : vp) {
        for (auto &&[mod, j] : path) {
            if (i % mod != 0) {
                ans[idx] = j + 1;
                break;
            }
        }
        path.emplace_back(i, idx);
    }
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}