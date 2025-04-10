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
    int n, m, x;
    cin >> n >> m >> x;
    vint v(2e7, 0);
    vint f(2e7, 0);
    for (size_t i = 1; i <= n; i++) {
        int p;
        cin >> p;
        f[i] = max(f[i - 1], v[(p ^ x)]);
        v[p] = i;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << (f[r] >= l ? "yes" : "no") << endl;
    }
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