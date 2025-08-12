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
    int n, q;
    cin >> n >> q;
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    ranges::sort(a);
    vint psum(n);
    psum[0] = a[0];
    for (size_t i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + a[i];
    }
    for (size_t i = 0; i < q; i++) {
        int b = 0;
        cin >> b;
        if (b > a.back()) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        auto _idx = ranges::lower_bound(a, b);
        int idx = _idx - a.begin();
        ans += (idx == 0 ? 0 : psum[idx - 1]);
        ans += (b - 1) * (n - idx);
        cout << ans + 1 << endl;
    }
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