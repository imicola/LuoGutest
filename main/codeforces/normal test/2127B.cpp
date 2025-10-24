//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    i64 cnt1 = 0, cnt2 = 0;
    i64 cnt3 = 0, cnt4 = 0;
    // b只会向一个方向前进，因为回头是亏的
    // 当b撞上一个障碍后a就有时间在b前进后的位置布置障碍
    if (x == 1 || x == n) {
        cout << 1 << endl;
        return;
    }
    for (i64 i = x; i < n && s[i] != '#'; i++) {
        if (s[i] == '#') break;
        cnt4++;
    }
    for (i64 i = x - 2; i >= 0 && s[i] != '#'; i--) {
        if (s[i] == '#') break;
        cnt3++;
    }
    i64 k1 = x - cnt3;
    i64 k2 = (n - x) - cnt4 + 1;
    i64 k3 = x;
    i64 k4 = n - x + 1;
    vint v = {k1, k2, k3, k4};
    sort(all(v));
    cout << v[1] << endl;
}
/*
    .###...##.#
    13 6
    .###.x...##.#
*/
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