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
    unordered_map<i64, i64> a;
    i64 Max = INT_MIN;
    for (i64 i = 0; i < n; i++) {
        i64 t = 0;
        cin >> t;
        a[t]++;
        Max = max(Max, t);
    }
    i64 ans = 0;
    for (i64 i = 1; i <= 2 * Max; i++) {
        i64 res = 0;
        for (i64 j = 1; j <= i - j; j++) {
            // cout << res << endl;
            if (j == i - j)
                res += a[j] / 2;
            else
                res += min(a[j], a[i - j]);
        }
        ans = max(res, ans);
    }
    cout << ans * 2;
}

// 1 2 3 5 6 7 8 9
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