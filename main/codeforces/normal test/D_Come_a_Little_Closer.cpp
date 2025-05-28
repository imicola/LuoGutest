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
// TODO 写题解
void solve()
{
    int n;
    cin >> n;
    vpii ma(n);
    for (auto &&[a, b] : ma) {
        cin >> a >> b;
    }
    if (n <= 2) {
        cout << n << endl;
        return;
    }
    auto spmx = [&](int &mx1, int &mx2) {
        if (mx1 < mx2) swap(mx1, mx2);
        return;
    };
    auto spmn = [&](int &mn1, int &mn2) {
        if (mn1 > mn2) swap(mn1, mn2);
        return;
    };
    int xmax1 = 0, xmax2 = 0, ymax1 = 0, ymax2 = 0, xmin1 = INT_MAX, xmin2 = INT_MAX, ymin1 = INT_MAX, ymin2 = INT_MAX;
    auto fx = [&](int x, int y) {
        xmax2 = max(xmax2, x);
        xmin2 = min(xmin2, x);
        ymax2 = max(ymax2, y);
        ymin2 = min(ymin2, y);
        spmx(xmax1, xmax2);
        spmn(xmin1, xmin2);
        spmx(ymax1, ymax2);
        spmn(ymin1, ymin2);
        return;
    };
    auto rex = [&](int x) {
        pii res = {xmax1, xmin1};
        if (x == xmax1) res.first = xmax2;
        if (x == xmin1) res.second = xmin2;
        return res.first - res.second + 1;
    };
    auto rey = [&](int y) {
        pii res = {ymax1, ymin1};
        if (y == ymax1) res.first = ymax2;
        if (y == ymin1) res.second = ymin2;
        return res.first - res.second + 1;
    };
    for (auto &&[a, b] : ma) {
        fx(a, b);
    }
    int ans = rex(-1) * rey(-1);
    for (auto &&[a, b] : ma) {
        int lx = rex(a);
        int ly = rey(b);
        if (lx * ly == n - 1) {
            ans = min(ans, min(lx * (ly + 1), ly * (lx + 1)));
        }
        else {
            ans = min(ans, lx * ly);
        }
    }
    cout << ans << endl;
}
// a00b
// 0000
// c00d

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