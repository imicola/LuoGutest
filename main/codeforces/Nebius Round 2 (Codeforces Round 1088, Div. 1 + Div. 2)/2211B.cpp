//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 x, y;
    cin >> x >> y;
    i64 absx = abs(x - y);
    i64 ans = 0;
    // 统计absx的因数对个数，包括1和absx本身
    for (i64 i = 1; i * i <= absx; i++) {
        if (absx % i == 0) {
            ans++;
            if (i * i != absx) {
                ans++;
            }
        }
    }
    cout << max(1ll, ans) << endl;
    for (i64 i = 0; i < x; i++) {
        cout << 1 << " ";
    }
    for (i64 i = 0; i < y; i++) {
        cout << -1 << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}