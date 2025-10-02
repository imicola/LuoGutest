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

i64 ksm(i64 a, i64 b, i64 MOD = 7)
{
    i64 ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    i64 n, q;
    cin >> n >> q;
    vint pre(n + 1);
    vint pow10(n + 1);
    pre[0] = 0;
    for (i64 i = 1; i <= n; i++) {
        char c;
        cin >> c;
        i64 d = c - '0';
        pre[i] = (pre[i - 1] * 10 + d) % 7;
        pow10[i] = ksm(10, i) % 7;
    }

    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 ans = (pre[r] - (pre[l - 1] * pow10[r - l + 1]) % 7 + 7) % 7;
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}