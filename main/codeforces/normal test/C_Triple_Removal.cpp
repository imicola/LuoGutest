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
    i64 n, q;
    cin >> n >> q;
    vint v0(n + 1), v1 = v0, v(n + 1, -1);
    for (i64 i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        v[i] = x;
        if (x == 0) {
            v0[i] = v0[i - 1] + 1;
            v1[i] = v1[i - 1];
        }
        else {
            v1[i] = v1[i - 1] + 1;
            v0[i] = v0[i - 1];
        }
    }
    vint pre00(n + 1, 0), pre11(n + 1, 0);
    for (i64 i = 1; i <= n; i++) {
        pre00[i] = pre00[i - 1];
        pre11[i] = pre11[i - 1];
        if (v[i] == 0 && v[i - 1] == 0) {
            pre00[i]++;
        }
        if (v[i] == 1 && v[i - 1] == 1) {
            pre11[i]++;
        }
    }
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 cnt0 = v0[r] - v0[l - 1];
        i64 cnt1 = v1[r] - v1[l - 1];
        i64 cnt00 = pre00[r] - pre00[l];
        i64 cnt11 = pre11[r] - pre11[l];
        if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        i64 ans = 0;
        if (cnt00 == 0 && cnt11 == 0) {
            ans = 2 + (r - l + 1 - 3) / 3;
        }
        else {
            ans = (r - l + 1) / 3;
        }
        cout << ans << endl;
    }
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