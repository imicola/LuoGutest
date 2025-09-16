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
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // 等腰三角形
    // 如果a,b平行于坐标轴
    if (x1 == x2) {
        cout << x1 + 2 << " " << y1 << endl;
        return;
    }
    if (y1 == y2) {
        cout << x1 << " " << y1 + 2<< endl;
        return;
    }
    cout << x1 << " " << y1 + 2 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}