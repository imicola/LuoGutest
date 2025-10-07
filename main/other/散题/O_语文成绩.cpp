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

void solve()
{
    i64 n, p;
    cin >> n >> p;
    vint v(n + 1,0);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vint diff(n + 2,0);
    diff[1] = v[1];
    for (i64 i = 2; i <= n; i++) {
        diff[i] = v[i] - v[i - 1];
    }
    while (p--) {
        i64 l, r, k;
        cin >> l >> r >> k;
        diff[l] += k;
        diff[r + 1] -= k;
    }
    i64 Min = LLONG_MAX;
    for (i64 i = 1; i <= n; i++) {
        diff[i] = diff[i - 1] + diff[i];
        Min = min(Min, diff[i]);
    }
    cout << Min << endl;
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