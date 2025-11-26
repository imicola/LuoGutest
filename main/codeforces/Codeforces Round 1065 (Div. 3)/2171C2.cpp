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
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n;
    cin >> n;
    vint a(n), b(n);
    i64 aj = 0, ma = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        aj ^= a[i];
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
        ma ^= b[i];
    }
    if (aj == ma) {
        cout << "Tie" << endl;
        return;
    }
    i64 diff = aj ^ ma;
    i64 k = 63 - __builtin_clzll(diff);

    for (i64 i = n - 1; i >= 0; i--) {
        i64 ck = (a[i] ^ b[i]);
        if ((ck >> k) & 1) {
            if (i % 2 == 0) {
                cout << "Ajisai" << endl;
            }
            else {
                cout << "Mai" << endl;
            }
            return;
        }
    }
    cout << "Tie" << endl;
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