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
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    /* 
        对于第 i 位而言，其发送消息的时间是 a[i] + b[i] + c[i - 1]
        则 sum i = sum (a[i] + b[i] + c[i - 1]) - c[n]
        最后一位是一定确定的，我们要让中间的最小
    */
    i64 n;
    cin >> n;
    struct P
    {
        i64 a, b, c;
        i64 sum;
    };
    vec<P> v(n);
    for (auto &&[i, j, k, l] : v) {
        cin >> i >> j >> k;
        l = i + j + k;
    }
    sort(all(v), [](P p1, P p2) { return p1.sum < p2.sum; });
    i64 ans = 0;
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
        ans += sum;
        ans += v[i].a + v[i].b;
        sum += v[i].sum;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}