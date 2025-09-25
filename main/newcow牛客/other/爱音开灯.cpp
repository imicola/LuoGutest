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
    i64 n, x;
    cin >> n >> x;
    // i64 cnt = 2;
    i64 cnt = 0;
    // 对x质因数分解
    for (i64 i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            if (i <= n) cnt++;
            // 判定有无整除数落在n区间
            if (x / i != i && x / i <= n) {
                cnt++;
            }
        }
    }
    cout << (cnt & 1 ? "ON" : "OFF");
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