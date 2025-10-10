//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    if (k == n * n - 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<string> g(n, string(n, '?'));
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < n; ++j) {
            if (k > 0) {
                g[i][j] = 'U';
                k--;
            }
            else if (i == n - 1) {
                if (j == n - 1)
                    g[i][j] = 'L';
                else
                    g[i][j] = 'R';
            }
            else {
                g[i][j] = 'D';
            }
        }
    }
    for (i64 i = 0; i < n; ++i) {
        cout << g[i] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}