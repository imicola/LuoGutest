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
    i64 x, m;
    cin >> x >> m;
    i64 cnt = 0;
    // (m - x)前的倍数
    i64 p = m - m % x;
    cnt = p / x;
    if (x < p) cnt--;
    if ((x ^ p) <= m && (x ^ p)> 0) cnt++;
    p += x;
    if ((x ^ p) <= m && (x ^ p) > 0) cnt++;
    for (i64 i = 1; i <= min(m, x); i++) {
        i64 xo = x ^ i;
        if (xo % i == 0) cnt++;
    }

    cout << cnt - (x <= m ? 1 : 0) << endl;
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