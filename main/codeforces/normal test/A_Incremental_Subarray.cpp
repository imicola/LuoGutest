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
    i64 n, m;
    cin >> n >> m;
    vint b(m);
    map<i64, i64> mp;
    bool ok = 0;
    for (i64 i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]]++;
        if (mp[b[0]] != 1) {
            ok = 1;
        }
    }
    if (ok || b[m - 1] < b[0]) {
        cout << 1 << endl;
        return;
    }
    i64 p = b[0];
    cout << n - b[m - 1] + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed)<< setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}