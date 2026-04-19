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

i64 ksm(i64 a, i64 b)
{
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    i64 n;
    cin >> n;
    vint v(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    i64 sum = 0;
    vint pre(n + 2);
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] ^ v[i];
    }
    vint k1(65), k0(65);
    for (i64 i = 0; i <= n; i++) {
        for (i64 j = 0; j <= 64; j++) {
            if ((pre[i] >> j) & 1) {
                k1[j]++;
            }
            else {
                k0[j]++;
            }
        }
    }
    for (i64 i = 0; i < 65; i++) {
        sum += k1[i] * k0[i] * ksm(2, i);
    }
    cout << sum << endl;
    // 1 1 1 0 1 0
    // 1 0 1 0 0 1
    // 1 1 0 1 1 0
    // 1 0 1 0 0 1
    // 0 3
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