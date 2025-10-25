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
    i64 n, k;
    cin >> n >> k;
    vint v(n);
    vint cnt(n + 1, 0);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    vint pre(n + 1,0);
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    i64 need = n - k;
    i64 g = 1;
    for (i64 d = n; d >= 2; d--) {
        i64 cnt2 = 0;
        i64 p = (4 * d <= n ? (n - pre[4 * d - 1]) : 0);
        if (d <= n) cnt2 += cnt[d];
        if (2 * d <= n) cnt2 += cnt[2 * d];
        if (3 * d <= n) cnt2 += cnt[3 * d];
        if (cnt2 + p >= need) {
            g = d;
            break;
        }
    }
    cout << g << endl;
}
/* 
14 3
14 12 7 12 9 9 12 4 3 1 3 6 9 13
*/
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