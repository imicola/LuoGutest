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
const constexpr i64 MOD = 1e9 + 7;

void solve()
{
    i64 n;
    cin >> n;
    i64 ansa = 1;
    i64 ansb = 1;
    for (i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        if (i == 0) {
            ansa = a, ansb = b;
            if (ansa < 0) ansa += MOD;
            if (ansb < 0) ansb += MOD;
            continue;
        }
        i64 ac = (ansa * a) % MOD;
        i64 bd = (ansb * b) % MOD;
        i64 bc = (ansb * a) % MOD;
        i64 ad = (ansa * b) % MOD;
        ansa = (ac - bd + MOD) % MOD;
        ansb = (bc + ad) % MOD;
    }
    cout << ansa << " " << ansb << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}