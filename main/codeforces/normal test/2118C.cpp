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
    i64 n, k;
    cin >> n >> k;
    vint v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    i64 buty = 0;
    vint addcost;
    addcost.reserve(1e5);
    for (i64 i = 0; i < n; i++) {
        i64 popcnt = __builtin_popcountll(v[i]);
        buty += popcnt;
        i64 bit = (v[i] == 0 ? 1 : 64 - __builtin_clzll(v[i]));
        for (i64 j = 0; j < 64; j++) {
            if (((v[i] >> j) & 1) != 0) continue;
            i64 cost = (1ll << j);
            if (cost > 0) addcost.emplace_back(cost);
        }
    }
    sort(all(addcost));
    for (auto &&i : addcost) {
        if (i > k) break;
        k -= i;
        buty++;
    }
    cout << buty << endl;
}
/* 
    一个数能达到最大的情况就是达到 全1下的二进制 1001 -> 1111 -> 11111
    我们是否可以计算其二进制位然后再计算其有几个1
    这两都可以O1实现
    但是我们不清楚0的位置
    我们贪心的选择1最少且二进制位数较小(大?)的数进行累加
    n只有5000，但是k有1e18
    如果有一个是全1下的，则我们必须让其变成2*n + 1才不会亏

    草，这题这样简单的啊
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