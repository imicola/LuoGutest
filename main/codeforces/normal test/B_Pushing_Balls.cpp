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
    vvint vv(n + 1, vint(m + 1, 0));
    vvint vx(n + 1, vint(m + 1, 0));
    vvint vy(n + 1, vint(m + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            vv[i][j] = (ch ^ 48);
            vx[i][j] += vx[i][j - 1] + vv[i][j];
            vy[i][j] += vy[i - 1][j] + vv[i][j];
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (vv[i][j] == 1) {
                if (vx[i][j] != j && vy[i][j] != i) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
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