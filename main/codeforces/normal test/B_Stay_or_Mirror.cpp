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
    vint p(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> p[i];
    }
    i64 ans = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 r = 0, l = 0;
        for (i64 j = 1; j < i; j++) {
            if (p[j] > p[i]) l++;
        }
        for (i64 j = i + 1; j <= n; j++) {
            if (p[j] > p[i]) r++;
        }
        ans += min(r, l);
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