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
    i64 n;
    cin >> n;
    vint v(n);
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    vint pre(n);
    pre[0] = v[0];
    for (i64 i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    i64 ans = LLONG_MAX;
    for (i64 i = 0; i < n; i++) {
        i64 now = pre[i];
        i64 res = i + 1;
        bool ok = 1;
        for (i64 j = i + 1; j < n;) {
            i64 _res = 0;
            i64 p = j;
            while (j < n && _res < now) {
                _res += v[j];
                j++;
            }
            if (_res != now) {
                ok = 0;
                break;
            }
            res = max(res, j - p);
        }
        if (ok) ans = min(res, ans);
    }
    cout << (ans == LLONG_MAX ? n : ans) << endl;
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