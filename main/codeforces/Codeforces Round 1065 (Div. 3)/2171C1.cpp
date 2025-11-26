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
    i64 aj = 0, mi = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) aj++;
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 1) mi++;
    }
    if (aj & 1)
        aj = 1;
    else
        aj = 0;

    if (mi & 1)
        mi = 1;
    else
        mi = 0;
    // cout << mi << " " << aj << endl;
    for (i64 i = 0; i < n; i++) {
        if (a[i] == b[i])
            continue;
        else {
            if (i % 2 == 0 && mi == 0) {
                mi ^= 1;
                aj ^= 1;
            }
            if (i % 2 == 1 && aj == 0) {
                mi ^= 1;
                aj ^= 1;
            }
        }
    }
    if (mi == aj) {
        cout << "Tie" << endl;
    }
    else {
        cout << (aj == 1 ? "Mai" : "Ajisai") << endl;
    }
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