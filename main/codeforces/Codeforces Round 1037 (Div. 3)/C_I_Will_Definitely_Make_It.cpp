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
    int n, k;
    cin >> n >> k;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    int under = v[k - 1];
    // auto [under,hight] = ranges::minmax(v);
    // 贪心:一开始所在位置就是我们能跨越的最大位置,而且我们只需要看比一开始大的
    ranges::sort(v);
    vint res;
    for (size_t i = 0; i < n; i++) {
        if (v[i] >= under) {
            res.emplace_back(v[i]);
        }
    }
    vint diff(n,0);
    for (size_t i = 0; i + 1 < res.size(); i++) {
        diff[i] = res[i + 1] - res[i];
    }
    cout << (ranges::max(diff) > under ? "NO" : "YES") << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}