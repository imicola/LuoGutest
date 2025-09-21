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
    i64 idx = 0, Max = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > Max) {
            Max = v[i];
            idx = i;
        }
    }
    if (Max > 1) {
        bool ok = 0;
        if (idx == 0 && v[idx + 1] == 0)
            ok = 1;
        else if (idx == n - 1 && v[idx - 1] == 0)
            ok = 1;
        else if (v[idx - 1] == 0 && v[idx + 1] == 0)
            ok = 1;
        cout << Max - (ok ? 1 : 0) << endl;
        return;
    }
    else {
        if (Max == 0) {
            cout << -1 << endl;
            return;
        }
        bool ok = 0;
        if (idx == 0 && v[idx + 1] == 0)
            ok = 1;
        else if (idx == n - 1 && v[idx - 1] == 0)
            ok = 1;
        else if (v[idx - 1] == 0 && v[idx + 1] == 0)
            ok = 1;
        cout << (ok ? -1 : 1) << endl;
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