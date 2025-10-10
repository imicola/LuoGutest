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
    stable_sort(all(vp), [](auto a, auto b) -> bool { return a.x + a.y < b.x + b.y; });
    i64 sum = 0;
    i64 mid = n / 2 - 1;
    for (i64 r = n - 1; r >= n / 2; r--) {
        cout << vp[mid].idx << " " << vp[r].idx << endl;
        sum += abs(vp[mid].x - vp[r].x) + abs(vp[mid].y - vp[r].y);
        mid--;
    }
    cout << sum << endl;
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