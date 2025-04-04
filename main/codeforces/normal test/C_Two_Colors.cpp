// #pragma GCC optimize(3)
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
    vint v(m);
    for (auto &&i : v) {
        cin >> i;
    }
    int ans  = 0;
    ranges::sort(v);
    for (size_t i = 0; i < m; i++) {
        int _i = n - v[i];
        int cnt = 0;
        for (size_t j = i + 1; j < m; j++) {
            if (v[j] >= _i) {
                cnt = m - j + 1;
                break;
            }
        }
        ans += (min(v[i], n - 1) + _i) * cnt * 2;
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