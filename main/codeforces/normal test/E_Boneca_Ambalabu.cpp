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
    vint v(n), c(30, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
        for (size_t k = 0; k < 30; k++) {
            c[k] += ((v[i] >> k) & 1);
        }
    }
    int ans = 0;
    int diffen = 0, maxcnt = -1;
    for (size_t i = 0; i < n; i++) {
        int p = v[i];
        int cnt = 0;
        for (size_t k = 0; k < 30; k++) {
            bool oxr1 = ((v[i] >> k) & 1);
            if (oxr1)
                cnt += (n - c[k]) * (1ll << k);
            else
                cnt += c[k] * (1ll << k);
        }
        if (cnt > maxcnt) {
            diffen = p;
            maxcnt = cnt;
        }
    }
    for (size_t i = 0; i < n; i++) {
        ans += (diffen ^ v[i]);
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