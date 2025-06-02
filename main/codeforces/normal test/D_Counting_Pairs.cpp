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
    int n, x, y;
    cin >> n >> x >> y;
    vint v(n);
    int sum = 0;
    for (auto &&i : v) {
        cin >> i;
        sum += i;
    }
    vint rv = v;
    ranges::sort(rv, greater<int>{});
    ranges::sort(v);
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        int now = sum - v[i], r = now - x, l = now - y;
        if (r < v[i]) continue;
        int idxl = 0, idxr = 0;
        if (l > v.back()) continue;
        auto itl = ranges::lower_bound(v, l);
        auto itr = ranges::lower_bound(rv, r, greater<int>{});
        if (itl == v.end())
            continue;
        else {
            idxl = itl - v.begin();
            if (idxl <= i) idxl = i + 1;
        }
        if (itr == v.end())
            idxr = n - 1;
        else {
            idxr = n - (itr - rv.begin()) - 1;
            if (idxr <= i) continue;
        }
        if (idxr < idxl) continue;
        ans += idxr - idxl + 1;
    }
    cout << ans << endl;
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