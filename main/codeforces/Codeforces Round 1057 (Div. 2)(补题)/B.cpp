//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 x, y, z;
    cin >> x >> y >> z;
    bool ok = 1;
    for (i64 i = 0; i < 34; i++) {
        i64 maska = (x >> i) & 1;
        i64 maskb = (y >> i) & 1;
        i64 maskc = (z >> i) & 1;
        if (maska + maskb + maskc == 2) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}