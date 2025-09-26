//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, t;
    cin >> n >> t;
    vpii vp(n);
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> vp[i].first;
        sum += vp[i].first;
    }
    for (i64 i = 0; i < n; i++) {
        cin >> vp[i].second;
    }
    sort(all(vp), [](pii a, pii b) { return a.first > b.first; });
    if (sum >= t) {
        cout << 0 << endl;
        return;
    }
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        i64 add = vp[i].second * vp[i].first;
        if (sum + add < t) {
            ans += vp[i].second;
            sum += add;
            continue;
        }
        else {
            i64 diff = t - sum;
            i64 need = (diff + vp[i].first - 1) / vp[i].first;
            ans += need;
            sum += add;
            break;
        }
    }
    if (sum < t) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}