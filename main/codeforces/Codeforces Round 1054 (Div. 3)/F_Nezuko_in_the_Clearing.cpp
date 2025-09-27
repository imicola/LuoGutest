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
    i64 h, d;
    cin >> h >> d;
    i64 l = 0, r = d;
    if (d == 0) {
        cout << 0 << endl;
        return;
    }
    i64 ans = 0;
    while (l < r) {
        i64 mid = (l + r) / 2;
        auto check = [&]() -> bool {
            i64 x = (d + mid) / (mid + 1);
            i64 r = d - x * mid;
            i64 diff = (((1 + x) * x) / 2) * mid;
            i64 rdiff = ((1 + r) * r) / 2;
            return diff + rdiff <= h + mid - 1;
        };
        if (check()) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans + d << endl;
}
// 4 3 2 1
// 0 1 2 3
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