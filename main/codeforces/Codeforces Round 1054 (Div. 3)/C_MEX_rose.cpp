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
    vint v(n);
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(all(v));
    i64 mex = 0;
    while (mp[mex] != 0) mex++;
    if (mex == k) {
        cout << 0 << endl;
        return;
    }
    if (mex > k) {
        cout << mp[k] << endl;
        return;
    }
    i64 ans = 0;
    for (i64 i = 0; i < k; i++) {
        if (mp[i] == 0) ans++;
    }
    cout << max(ans, mp[k]) << endl;
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