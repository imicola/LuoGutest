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
    i64 n, q;
    cin >> n >> q;
    vint a(n), b(n);
    for (auto &&i : a) cin >> i;
    for (auto &&i : b) cin >> i;
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) sum += min(a[i], b[i]);
    // cout << sum << endl;
    while (q--) {
        char c;
        i64 x, v;
        cin >> c >> x >> v;
        i64 &ax = a[x - 1], &bx = b[x - 1];
        i64 minn = min(ax, bx);
        if (c == 'A') {
            if (minn == ax) sum -= ax, sum += min(bx, v);
            if (ax  != bx && minn == bx && v < bx) sum -= (bx - v);
            ax = v;
        }
        else {
            if (minn == bx) sum -= bx, sum += min(ax, v);
            if (minn == ax && v < ax) sum -= (ax - v);
            bx = v;
        }
        cout << sum << endl;
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