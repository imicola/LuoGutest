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
    vpii vp(n + 1);
    for (i64 i = 1; i <= n; i++) {
        i64 x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    i64 cnt = 0;
    i64 ans = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 diff = vp[i].first - cnt;
        ans += diff;
        cnt = vp[i].first;
        // cout << diff << endl;
        if (vp[i].second != ans % 2 && (diff != 0 || diff != 1)) {
            ans--;
        }
    }
    cout << ans + (m - cnt) << endl;
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