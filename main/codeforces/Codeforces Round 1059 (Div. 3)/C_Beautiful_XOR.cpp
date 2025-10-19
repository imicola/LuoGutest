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

void solve()
{
    i64 a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (a == 0) {
        cout << -1 << endl;
        return;
    }
    if (b == 0) {
        cout << 1 << endl;
        cout << a << endl;
        return;
    }
    i64 k1 = 63 - __builtin_clzll(a);
    i64 k2 = 63 - __builtin_clzll(b);
    if (k1 < k2) {
        cout << -1 << endl;
        return;
    }
    if (k1 == k2) {
        cout << 1 << endl;
        cout << (a ^ b) << endl;
        return;
    }
    cout << 2 << endl;
    i64 top = 1LL << k1;
    i64 mask = top - 1;
    i64 x1 = (a & mask) ^ b;
    i64 x2 = top;
    cout << x1 << " " << x2 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}