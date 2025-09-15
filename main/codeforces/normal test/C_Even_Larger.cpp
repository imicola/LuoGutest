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

/* 
    我们的目标是将v的所有子数组变成好的
    形式化好的的目标
    我们可以构造滑动窗口diff计算每一个子数组的odd序列和 - even序列和的数量
    如果当前子数组diff > 0 说明其是好的
    当我们滑动时候
    滑动窗口是对的对的
    错的错的
    我们对所有 奇偶奇偶奇偶
               0 1 1 1 0 1
    magic 讨论
    我们对偶数位置上不难发现,单一偶数配两个奇数是可能的最差情况
    那我们就对每个偶数位置讨论,让 长度  L = 3 的区间变为0同时 [l , c , r] 中只有 r 会影响下一个长度为3的区间
    所以我们就尽量往减少 r 的思路去讨论
*/
void solve()
{
    i64 n;
    cin >> n;
    vint v(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    i64 ans = 0;
    if ((n & 1) == 0) v.emplace_back(0);
    for (i64 i = 2; i <= n; i += 2) {
        i64 &c = v[i], &l = v[i - 1], &r = v[i + 1];
        if (c >= l + r) continue;
        // 如果 c < l + r
        if (c < l + r) {
            i64 delta = l + r - c;
            ans += delta;
            if (c > l && c > r) {
                
                r -= delta;
            }
            else if (c > l && c <= r) {
                r -= delta;
            }
            else {
                l = c;
                r = 0;
            }
        }
    }
    cout << ans << endl;
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