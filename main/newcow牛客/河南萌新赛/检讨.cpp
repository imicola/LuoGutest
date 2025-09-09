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
    i64 n, L;
    cin >> n >> L;
    vint v(n);
    for (auto &&i : v) cin >> i;
    /* 
    题目要求我们求块长大于L的最大平均数
    我们对这个最大平均数二分答案
    我们需要构造一个情景使得其程序单调性让其可以被二分
    即我们将 求最大平均数 变为 判断某段平均数是否大于 x 
    进行数学变化 (pre[L - i] / L) >= x -> sum{pre[L - i] - x} >= 0 
    有 sum[i] = sum[i - 1] + v[i]
    即变化为 S[i] = S[i-1] + v[i] - x
    至于如何在O(n)来维护最大前缀和以及为什么是s[i] - minpre会在笔记中严格证明
    */
    auto check = [&](double mid) -> bool {
        vector<double> s(n, 0.0);
        s[0] = (v[0] - mid);
        for (i64 i = 1; i < n; i++) {
            s[i] = s[i - 1] + (v[i] - mid);
        }
        double minpre = 0.0;
        // 注意下标越界问题
        for (i64 i = L - 1; i < n; i++) {
            if (i >= L) minpre = min(minpre, s[i - L]);
            if (s[i] - minpre >= 0) return 1;
        }
        return 0;
    };
    double l = ranges::min(v), r = ranges::max(v);
    double ans = 0.0;
    for (i64 i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(8);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}