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
    vint v(n + 1);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    vint p = v;
    p[0] = LLONG_MAX;
    for (size_t i = 1; i <= n; i++) {
        p[i] = min(p[i - 1], v[i]);
    }
    for (size_t i = 2; i <= n; i++) {
        if (v[i] >= p[i] * 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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