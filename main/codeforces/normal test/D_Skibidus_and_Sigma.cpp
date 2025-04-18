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
    vvint mp(n + 1, vint(m + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        int sum = 0;
        for (size_t j = 1; j <= m; j++) {
            cin >> mp[i][j];
            sum += mp[i][j];
        }
        mp[i][0] = sum;
    }
    ranges::sort(mp, [](vint a, vint b) { return a[0] > b[0]; });
    vint psumv(n * m + 1, 0);
    int cnt = 1;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 1; j <= m; j++) {
            psumv[cnt] = mp[i][j];
            cnt++;
        }
    }
    for (size_t i = 1; i <= n * m; i++) {
        psumv[i] = psumv[i - 1] + psumv[i];
    }
    int ans = 0;
    for (size_t i = 1; i <= n * m; i++) {
        ans += psumv[i];
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