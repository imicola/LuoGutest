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
    int n, k, ans = 0;
    cin >> n >> k;
    vint v(n);
    int maxx = -1;
    for (auto &&i : v) {
        cin >> i;
        maxx = max(maxx, i);
    }
    if (k == 1) {
        if (maxx != v.back() && maxx != v.front()) {
            cout << maxx + max(v.back(), v.front()) << endl;
            return;
        }
        ranges::sort(v, greater<int>());
        auto v2 = views::take(v, 2);
        for (auto &&i : v2) {
            ans += i;
        }
        cout << ans << endl;
        return;
    }
    else {
        ranges::sort(v, greater<int>());
        auto v2 = views::take(v, k + 1);
        for (auto &&i : v2) {
            ans += i;
        }
        cout << ans << endl;
    }
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