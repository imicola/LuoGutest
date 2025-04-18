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
    vvint v(n + 1, vint(m + 1, 0));
    map<int, int> mp, mp2;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == v[i - 1][j] || v[i][j] == v[i][j - 1]) {
                mp[v[i][j]] = 1;
            }
            mp2[v[i][j]] = 1;
        }
    }
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0, fi = 0;
    for (auto &&[i, j] : mp) {
        mp2[i] = 0;
        if (fi == 0) {
            fi = 1;
            continue;
        }
        ans += 2;
    }
    for (auto &&[i, j] : mp2) {
        if (j != 0) ans++;
    }
    if (mp.empty()) ans--;
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