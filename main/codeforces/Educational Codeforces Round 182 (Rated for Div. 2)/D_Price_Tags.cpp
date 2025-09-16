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
    vint c(n);
    vint cnt(2e5 + 10);
    i64 maxnum = -1;
    // cout << mp[0] << endl;
    for (i64 i = 0; i < n; i++) {
        cin >> c[i];
        cnt[c[i]]++;
        maxnum = max(maxnum, c[i]);
    }
    i64 ans = LLONG_MIN;
    if (maxnum == 1) {
        cout << n << endl;
        return;
    }
    vint pre(maxnum + 10);
    for (i64 i = 1; i <= maxnum; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    for (i64 x = 2; x <= maxnum + 1; x++) {
        i64 kk = 0;
        i64 p = 0;
        for (i64 l = 1, op = 1; l <= maxnum; l += x, op++) {
            // op 整除数
            i64 r = min(l + x - 1, maxnum);
            if (l > r) continue;
            // 块长 
            i64 LR = r - l + 1;
            // 块内容
            i64 k2 = pre[r] - pre[l - 1];
            // 块贡献
            p += k2 * op;
            kk += (cnt[op] >= k2 ? k2 : cnt[op]);
        }
        ans = max(ans, p - max(0ll, n - kk) * k);
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