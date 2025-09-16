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
    vint v(n + 1);
    i64 ans = 0, ok = 0, idx1 = 0, idx2 = -1, idx3 = n + 1;
    // 他妈的这也太蠢了
    vint cnt;
    map<i64, i64> mp;
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] == 0) {
            ok++;
            if (ok == 1) idx1 = i;
        }
        mp[v[i]]++;
    }
    if (ok == 1) {
        // wa 2
        if (!mp.contains(idx1)) v[idx1] = idx1;
    }
    for (i64 i = 1; i <= n; i++) {
        if (v[i] != i) {
            idx2 = i;
            break;
        }
    }
    for (i64 i = n; i >= 1; i--) {
        if (v[i] != i) {
            idx3 = i;
            break;
        }
    }
    if (idx2 == -1) {
        cout << 0 << endl;
        return;
    }
    cout << (idx3 - idx2 == 0 ? 0 : idx3 - idx2 + 1) << endl;
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