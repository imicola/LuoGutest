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
    i64 k = 0;
    i64 _min = LLONG_MAX;
    vint Min;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        _min = min(_min, v[i]);
        Min.emplace_back(_min);
        k += _min;
    }
    if (v[0] == _min) {
        cout << v[0] * 2 << endl;
        return;
    }
    if (v[0] > v[1]) {
        cout << v[0] + v[1] << endl;
        return;
    }
    cout << v[0] * 2 << endl;
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