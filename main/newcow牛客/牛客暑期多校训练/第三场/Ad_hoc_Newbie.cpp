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
    vint f(n + 1);
    for (size_t i = 1; i <= n; i++) {
        cin >> f[i];
    }
    vint vis(n + 1, 0);
    vvint a(n + 1, vint(n + 1, 0));
    for (size_t i = 1; i <= n; i++) {
        if (!vis[i]) {
            vint path;
            int cnt = i;
            while (!vis[cnt]) {
                vis[cnt] = 1;
                path.emplace_back(cnt);
                cnt = f[cnt];
            }
            int k = path.size();
            if (k == 0) continue;
            vint pos(n + 1);
            for (size_t j = 0; j < k; j++) {
                pos[path[j]] = j;
            }
            for (auto &&idx1 : path) {
                for (auto &&idx2 : path) {
                    a[idx1][idx2] = (pos[idx2] - pos[idx1] + k) % k;
                }
            }
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
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