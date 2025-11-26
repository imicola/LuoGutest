//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

/* 
    思考:
    我们需要判断这个图是否连通
    那我们考虑图不连通的情况
    假设大的都在前面,自然不连通 5 1 2 3 4 x
                                1 4 2 3 5 x
    就是我们的图应该是要让左边部分的所有数字都小于右边部分的所有数字
    我们尝试对每个点分割
    如果有个点前的min = n - i
    说明前面是比n-i大的数
    则不可能构成

*/

void solve()
{
    i64 n;
    cin >> n;
    vint p(n);
    for (i64 i = 0; i < n; i++) {
        cin >> p[i];
    }
    i64 Min = LLONG_MAX;
    for (i64 i = 0; i < n - 1; i++) {
        Min = min(Min, p[i]);
        if (Min == n - i) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}