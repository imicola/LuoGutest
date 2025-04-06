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
    int n, k, t;
    cin >> n >> k >> t;
    vint v(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> v[i];
    }
    auto check = [&](int mid) -> bool {
        vint sortv(mid + 1, 0);
        for (int i = 1; i <= mid; i++) sortv[i] = v[i];
        // vint sortv = vint(v.begin() + 1,v.begin() + mid);
        sort(v.begin() + 1, v.begin() + mid + 1);
        vint pre(mid + 1, 0);  // E(x)
        vint pre2(mid + 1, 0); //E(x^2)
        for (size_t i = 1; i <= mid; i++) {
            pre[i] = pre[i - 1] + sortv[i];
            pre2[i] = pre2[i - 1] + sortv[i] * sortv[i];
        }
        for (size_t i = 1; i <= mid - k + 1; i++) {
            int s = k * (pre2[i + k - 1] - pre2[i - 1]) - (pre[i + k - 1] - pre[i - 1]) * (pre[i + k - 1] - pre[i - 1]);
            if (s <= k * k * t) {
                return 1;
            }
        }
        return 0;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            // ans = mid;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << (check(l) == 0 ? -1 : l);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}