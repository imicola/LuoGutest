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
    i64 x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    if (x == 0) {
        cout << 1 << endl;
        return;
    }
    // x / 2 -> x >> 1;
    // x | z -> 任意位置变成1
    // 不断 >> 1直到x中没有1在y这个二进制位下的相同
    // 或者有如果(x >> i) | y == y时候x就是正确的
    i64 ans = 1e18;
    for (i64 j = 0; j <= 65; j++) {
        i64 b = (x >> j);
        // 当b的所有1都在y中有对应即可，即
        if ((b & (~y)) == 0) {
            ans = min(ans, j + 1);
        }
    }
    for (i64 t = 0; t <= 65; t++) {
        i64 a = x >> t;
        if (a == y) {
            ans = min(ans, t);
            break;
        }
        else if (a < y) {
            if ((a | y) == y) ans = min(ans, t + 1);
        }
        if (a == 0) break;
    }
    cout << ans << endl;
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