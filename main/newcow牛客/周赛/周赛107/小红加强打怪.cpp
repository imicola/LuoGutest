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
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    // ranges::sort(v,greater{});
    int now = 1;
    int ans = 0;
    // (1 + n)n/2 > i
    auto check = [&](int i) {
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid * mid + mid - 2 * i >= 0) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (auto &&i : v) {
        ans += check(i);
        // cout << i << endl;
        // cout << ans << endl;
    }
    cout << ans;
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