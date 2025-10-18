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


/* 
    我们先计算(1,2)(3,4)的差和
    与        (2,3)(4,5)...的差和
    对于每一多一个人，我们就可以将后面的人和前面的人匹配
*/

void solve()
{
    i64 n;
    cin >> n;
    vint v(2 * n);
    for (i64 i = 0; i < 2 * n; i++) cin >> v[i];
    i64 diff1 = 0, diff2 = 0;
    for (i64 i = 0; i < 2 * n; i += 2) {
        diff1 -= v[i];
    }
    for (i64 i = 1; i < 2 * n; i += 2) {
        diff1 += v[i];
        diff2 -= v[i];
    }
    for (i64 i = 2; i < 2 * n; i += 2) diff2 += v[i];
    diff2 += 2 * v[2 * n - 1] - v[0];
    vint ans(n + 3,0);
    ans[1] = diff1, ans[2] = diff2;
    for (i64 i = 3; i <= n; i++) {
        ans[i] = ans[i - 2] + (v[2 * n - i + 1] - v[i - 2]) * 2;
    }
    for (i64 i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
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