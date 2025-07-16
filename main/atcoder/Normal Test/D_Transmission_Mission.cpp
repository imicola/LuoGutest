//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n, m;
    cin >> n >> m;
    vint x(n);
    int sum = 0;
    for (auto &&i : x) {
        cin >> i;
    }
    // 如果 m > n,无需判断直接输出0
    if (m >= n) {
        cout << 0 << endl;
        return;
    }
    // 对坐标排序
    ranges::sort(x);
    // 计算各个点之间的距离,并计算距离总和
    vint diff(n - 1);
    for (size_t i = 0; i + 1 < n; i++) {
        diff[i] = x[i + 1] - x[i];
        sum += diff[i];
    }
    // 排序距离
    ranges::sort(diff, greater<int>{});
    // 最后会有min(n-1,m-1)个 距离块 没有被包裹在圆内
    int le = min(n - 1, m - 1);
    // 减去这些没有被包裹的距离块
    for (size_t i = 0; i < le; i++) {
        sum -= diff[i];
    }
    cout << sum;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}