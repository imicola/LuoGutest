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
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    i64 ans1 = 0, ans2 = 0;
    i64 cur = 0;
    for (auto &&[a, b] : mp) {
        if (a % 2 == 0) {
            ans1 += b * (a / 2);
            ans2 += b * (a / 2);
        }
        else {
            if (cur == 0) {
                ans1 += b * ((a + 1) / 2);
                ans2 += b * (a / 2);
            }
            else {
                ans2 += b * ((a + 1) / 2);
                ans1 += b * (a / 2);
            }
            cur ^= 1;
        }
    }
    cout << ans1 << " " << ans2 << endl;
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