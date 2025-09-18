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
    i64 n, k;
    cin >> n >> k;
    vint a(n), b(k);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 i = 0; i < k; i++) {
        cin >> b[i];
    }
    // 尽量使用折扣卷
    // 从小开始用
    ranges::sort(a);
    ranges::sort(b);

    i64 it1 = n, it2 = 0;
    while (it1 > 0) {
        if (it2 > k - 1) break;
        i64 add = b[it2];
        it1 -= add;
        if (it1 < 0) break;
        // cout << a[it1] << " " << it1 <<  endl;
        a[it1] = 0;
        it2++;
        // cout << it2 << endl;
    }
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
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