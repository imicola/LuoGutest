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
    i64 n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    i64 p1 = 0, p2 = 0;
    p1 = min({n - x1 + 1, x1, n - y1 + 1, y1});
    p2 = min({n - x2 + 1, x2, n - y2 + 1, y2});
    cout << abs(p1 - p2) << endl;
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