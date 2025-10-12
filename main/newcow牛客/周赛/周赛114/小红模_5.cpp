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
const constexpr i64 MOD = 1e9 + 7;

void solve()
{
    i64 n;
    cin >> n;
    i64 ans = 0;
    i64 pre = 2;
    for (i64 i = 3; i <= n - 1; i++) {
        // cout << i << " " << pre << endl;
        pre = i * pre % MOD;
    }
    if (n <= 3) pre = max(1ll, n - 1);
    // cout << pre << " " << endl;
    for (i64 i = 1; i <= n; i++) {
        ans = (ans + pre * (i % 5) % MOD) % MOD;
    }
    cout << ans % MOD << endl;
}

void solve2()
{
    i64 n = 4;
    vint v = {1, 2, 3, 4, 5, 6, 7};
    map<i64, i64> mp;
    do {
        mp[v.back()]++;
    } while (next_permutation(all(v)));
    for (auto &&[a, b] : mp) {
        cout << a << " " << b << endl;
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