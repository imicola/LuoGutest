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
    i64 n;
    cin >> n;
    struct point
    {
        i64 x, y, idx;
    };
    vector<point> vp(n);
    for (i64 i = 0; i < n; i++) {
        cin >> vp[i].x >> vp[i].y;
        vp[i].idx = i + 1;
    }
    sort(all(vp), [](auto a, auto b) -> bool { return a.x < b.x; });
    sort(vp.begin(), vp.begin() + n / 2, [](auto a, auto b) -> bool { return a.y < b.y; });
    sort(vp.begin() + n / 2, vp.end(), [](auto a, auto b) -> bool { return a.y < b.y; });
    i64 sum = 0;
    for (i64 i = 0, r = n - 1; i < r; i++, r--) {
        auto [a, b, c] = vp[i];
        auto [a1, b1, c1] = vp[r];
        cout << c << " " << c1 << endl;
        sum += abs(a - a1) + abs(b - b1);
    }
    // cout << sum << endl;
}

void solve2()
{
    i64 n;
    cin >> n;
    struct point
    {
        i64 x, y, idx;
    };
    vector<point> vp(n);
    for (i64 i = 0; i < n; i++) {
        cin >> vp[i].x >> vp[i].y;
        vp[i].idx = i + 1;
    }
    vint a = {8, 9, 7, 2, 6};
    vint b = {1, 10, 5, 3, 4};
    i64 sum = 0;
    for (auto &&i : a) {
        i--;
    }
    for (auto &&i : b) {
        i--;
    }
    for (size_t i = 0; i < 5; i++) {
        sum += abs(vp[a[i]].x - vp[b[i]].x) + abs(vp[a[i]].y - vp[b[i]].y);
    }
    cout << sum << endl;
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