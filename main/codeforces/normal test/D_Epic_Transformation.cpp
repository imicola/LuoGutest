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
    i64 Max = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        Max = max(Max, mp[v[i]]);
    }
    if (Max > n - Max) {
        cout << 2 * Max - n << endl;
    }
    else {
        cout << ((n - 2 * Max) % 2 == 0 ? 0 : 1) << endl;
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