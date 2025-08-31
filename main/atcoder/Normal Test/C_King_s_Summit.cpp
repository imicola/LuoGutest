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
    int n;
    cin >> n;
    // int diff1 = INT_MIN,diff2 = INT_MIN;
    vint x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        // int x1, y1;
        cin >> x[i] >> y[i];
    }
    ranges::sort(x);
    ranges::sort(y);
    cout << ((max(x.back() - x.front(), y.back() - y.front())) + 1) / 2;
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