//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    struct printer
    {
        i64 t, l, w;
    };
    vector<printer> v(n);
    for (auto &&[i, j, k] : v) {
        cin >> i >> j >> k;
    }
    i64 l = 0, r = 2e18;
    i64 ans = 0;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        auto check = [&](i64 mid) -> bool {
            i128 res = 0; 
            for (auto &&[t, lx, w] : v) {
                i64 cycle = t * lx + w;
                i64 work = mid / cycle;
                i64 rx = mid % cycle;
                i64 k1 = work * lx;
                i64 k2 = (rx >= t * lx) ? lx : (rx / t);
                res += (i128)k1 + (i128)k2;
                if (res >= k) return true;
            }
            return res >= k;
        };
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}