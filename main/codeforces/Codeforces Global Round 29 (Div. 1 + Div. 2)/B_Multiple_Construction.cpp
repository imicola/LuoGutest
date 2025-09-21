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
    i64 n;
    cin >> n;
    vector<i64> res(2 * n + 1);
    i64 idx = 1;
    for (i64 i = n; i >= 1; i--) {
        if (i % 2 == 0) {
            res[idx] = i;
            res[idx + i] = i;
            idx++;
        }
    }
    idx = n / 2 + 1;
    for (i64 i = n; i >= 1; i--) {
        if (i & 1) {
            res[idx] = i;
            if (i == 1) {
                res[2 * n] = 1;
                break;
            }
            res[idx + i] = i;
            while (res[idx] != 0) {
                idx++;
            }
        }
    }
    for (i64 i = 1; i <= 2 * n; i++) {
        cout << res[i] << " ";
    }

    cout << endl;
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