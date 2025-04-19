//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
#define size_t int
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
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    vint psum(n), rsum(n);
    rsum[n - 1] = abs(v[n-1] < 0 ? v[n-1] : 0);
    psum[0] = abs(v[0] > 0 ? v[0] : 0);
    for (size_t i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + (v[i] > 0 ? v[i] : 0);
        rsum[n - i - 1] = rsum[n - i] + abs(v[n - i - 1] < 0 ? v[n - i - 1] : 0);
    }
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        ans = max(ans, psum[i] + rsum[i]);
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