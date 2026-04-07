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
    // 从后往前逆推
    vvint v(n + 1, vint(n + 1));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= i; j++) {
            cin >> v[i][j];
        }
    }
    for (i64 i = n - 1; i >= 1; i--) {
        for (i64 j = 1; j <= i; j++) {
            v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
        }
    }
    cout << v[1][1] <<endl;
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