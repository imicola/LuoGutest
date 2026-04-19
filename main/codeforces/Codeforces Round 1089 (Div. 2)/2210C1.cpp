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
    vint a(n + 2);
    vint b(n + 2);
    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i64 i = 1; i <= n; i++) {
        cin >> b[i];
    }
    i64 ans = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 g1 = gcd(a[i], a[i + 1]);
        i64 g2 = gcd(a[i], a[i - 1]);
        if (i == 1) {
            if (g1 < b[i]) ans++;
        }
        else if (i == n) {
            if (g2 < b[i]) ans++;
        }
        else
        {
            if (b[i] > lcm(g1, g2)) ans++;
        }
        
    }
    cout << ans << endl;
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