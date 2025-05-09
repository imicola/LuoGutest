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

struct vxp
{
    int point, val, idx;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vxp> vp(m);
    for (size_t i = 0; i < m; i++) {
        auto &&[k, j, t] = vp[i];
        cin >> k >> j;
        t = i + 1;
    }
    
    ranges::stable_sort(vp, [&](vxp a, vxp b) { return a.val < b.val; });
    int res = 0;
    vpii ans;
    for (size_t i = 0, k = 2 * n - 1; i < n; i++, k--) {
        res += vp[i].val + vp[k].val;
        ans.emplace_back(vp[i].point, vp[i].idx);
        ans.emplace_back(vp[k].point, vp[k].idx);
    }
    cout << res << endl;
    ranges::stable_sort(ans, [&](pii a, pii b) { return a.first < b.first; });
    for (int i = 0, k = 2 * n - 1; i < n; i++, k--) {
        cout << ans[i].second << " " << ans[k].second << endl;
    }
    cout << endl;
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