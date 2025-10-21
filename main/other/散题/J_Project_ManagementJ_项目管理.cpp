//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    struct P
    {
        i64 idx, v, j;
    };
    vector<P> vp(n);
    for (i64 i = 0; i < n; i++) {
        auto &&[idx, vx, j] = vp[i];
        cin >> vx >> j;
        idx = i + 1;
    }
    sort(all(vp), [](auto a, auto b) { return (a.v == b.v ? a.j > b.j : a.v > b.v); });
    vint ans;
    ans.reserve(n);
    for (i64 i = 0; i < n;) {
        i64 sz = ans.size();
        i64 valx = vp[i].v;
        while (i < n && vp[i].v == valx) {
            auto [_idx, val, j] = vp[i];
            if (j >= sz) ans.emplace_back(_idx);
            i++;
        }
    }
    cout << ans.size() << endl;
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