//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    vint a(n);
    vint b(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
    }
    vint prea(n);
    vint preb(n);
    prea[0] = a[0];
    preb[0] = b[0];
    for (i64 i = 1; i <= n; i++) {
        prea[i] = prea[i - 1] + a[i];
    }
    for (i64 i = 1; i <= n; i++) {
        preb[i] = preb[i - 1] + b[i];
    }
    for (i64 i = 0; i < n; i++)
    {
        
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