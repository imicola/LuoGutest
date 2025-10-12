//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
#define double long double
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

// 我们对x排序，关注y,如果y == d则说明这个地方一定有一个
// 如果y < d,则我们判断这个y恰好在圆周的情况从而确定一个圆
// 往后的点判断是否在这个圆内，如果没有则更新圆
/* 
    问题是，如何在logn时间或者常数时间确定这个圆以及如何确定后面的点是否在这个圆内
    考虑已知条件
    我们可以轻松计算当半径为d时候这个点(x,y)在圆周上且圆心在x周的圆心坐标
    C(r = (x - sqrt(d^2 - y^2)),0)
    写出圆方程: (X - r)^2 + Y^2 = d^2
    对于新点(x',y') 比较 Y^2 = d^2 - (x' - r)^2 > y^2 ? 下一个点 ：更新
*/
/* 
    或者我们尝试反过来思考
    对于每一个点我们都可以构造一个圆在x轴上获得可覆盖区间[p1,p2]
    我们计算所有点的可覆盖区间并按p2排序,因为我们需要最大化对后续岛的影响
    维护一个R
    如果下一个点p1 <= R,不操作
    如果大于R，将R更新到p2并且cnt++
    这个好写多了
*/

void solve()
{
    i64 n, d;
    cin >> n >> d;
    vector<pair<double, double>> vp(n);
    bool ok = 0;
    auto calc = [&](i64 x, i64 y) -> pair<double, double> {
        if (y > d) {
            return {0, 0};
        }
        return {x - sqrt(d * d - y * y), x + sqrt(d * d - y * y)};
    };
    for (i64 i = 0; i < n; i++) {
        i64 x, y;
        cin >> x >> y;
        if (y > d) ok = 1;
        vp[i] = calc(x, y);
    }
    // 如果存在大于d的y坐标则不可能覆盖全部
    if (ok) {
        cout << -1 << endl;
        return;
    }
    sort(all(vp), [](auto a, auto b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    double pos = -0x3f3f3f3f;
    i64 cnt = 0;
    for (auto &&[a, b] : vp) {
        if (pos < a) {
            pos = b;
            cnt++;
        }
    }
    cout << cnt << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(0);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}