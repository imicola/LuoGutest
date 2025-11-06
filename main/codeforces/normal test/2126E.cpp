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
    i64 n;
    cin >> n;
    vint p(n + 1);
    vint s(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (i64 i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vint ans(n + 1, 0);
    i64 ok = 1;
    for (i64 i = n; i >= 1; i--) {
        ans[i] = lcm(p[i], s[i]);
    }
    if (ans[1] != p[1]) ok = 0;
    if (ans[n] != s[n]) ok = 0;
    for (i64 i = 2; i <= n; i++) {
        if (gcd(p[i - 1], ans[i]) != p[i]) ok = 0;
    }
    for (i64 i = n - 1; i >= 1; i--) {
        if (gcd(s[i + 1], ans[i]) != s[i]) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
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