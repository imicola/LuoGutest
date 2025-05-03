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
    int n, l, r;
    cin >> n >> l >> r;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    vint vl(r), vr(n - l + 1);
    for (size_t i = 0; i < r; i++) {
        vl[i] = v[i];
    }
    for (size_t i = n - 1, k = 0; i >= l - 1 ; i--, k++) {
        vr[k] = v[i];
    }
    ranges::sort(vl);
    ranges::sort(vr);
    int p = r - l + 1;
    int ans = 0, ans2 = 0;
    for (size_t i = 0; i < p; i++) {
        ans += vr[i];
        ans2 += vl[i];
    }
    cout << min(ans, ans2) << endl;
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