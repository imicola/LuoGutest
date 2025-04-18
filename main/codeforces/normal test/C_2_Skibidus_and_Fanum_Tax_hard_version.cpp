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
    int n, m;
    cin >> n >> m;
    vint a(n), b(m);
    for (auto &&i : a) {
        cin >> i;
    }
    for (auto &&i : b) {
        cin >> i;
    }
    ranges::sort(b);
    a.insert(a.begin(), INT_MIN);
    for (size_t i = 1; i <= n; i++) {
        auto it = lower_bound(all(b), -14, [&](int a1, int k) { return a1 - a[i] < a[i - 1]; });
        if (it == b.end()) continue;
        int t = *it;
        if (a[i] < a[i - 1] && t - a[i] < a[i - 1]) continue;
        a[i] = min((a[i] < a[i - 1] ? INT_MAX : a[i]), (t - a[i] < a[i - 1] ? INT_MAX : t - a[i]));
    }
    cout << (ranges::is_sorted(a) ? "YES" : "NO") << endl;
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