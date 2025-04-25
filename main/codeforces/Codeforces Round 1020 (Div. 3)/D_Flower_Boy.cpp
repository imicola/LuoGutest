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
    vint a(n + 1);
    vint b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vint psum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1];
        if (psum[i] < m && a[i] >= b[psum[i] + 1]) psum[i]++;
    }
    vector<int> suf(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (suf[i] < m && a[i] >= b[m - suf[i]]) suf[i]++;
    }
    int ans = LLONG_MAX;
    for (size_t i = 0; i <= n; i++) {
        int p1 = psum[i];
        if (p1 == m) {
            cout << 0 << endl;
            return;
        }
        if (suf[i + 1] >= m - p1 - 1) {
            ans = min(ans, b[p1 + 1]);
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
        return;
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