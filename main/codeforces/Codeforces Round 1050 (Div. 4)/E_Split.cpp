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
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    map<i64, i64> mp;
    for (auto &&i : a) {
        mp[i]++;
    }
    vint b(n + 1, 0);
    i64 ok = 1;
    for (i64 i = 1; i <= n; i++) {
        if (mp[i] % k != 0) {
            ok = 0;
        }
        b[i] = mp[i] / k;
    }
    if (!ok) {
        cout << 0 << endl;
        return;
    }
    i64 ans = 0;
    vint res(n + 1,0);
    for (i64 i = 0, j = 0; i < n; i++) {
        res[a[i]]++;
        while (res[a[i]] > b[a[i]]) {
            res[a[j]]--;
            j++;
        }
        ans += (i - j + 1);
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