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
    vint p(n);
    for (i64 i = 0; i < n; i++) {
        cin >> p[i];
    }
    i64 ok = 0;
    i64 idx = 0;
    while (idx < n && p[idx] < p[idx + 1]) {
        idx++;
    }
    if (idx == n) {
        cout << "Yes" << endl;
        return;
    }
    // cout << "idx" << idx << endl;
    for (i64 i = idx + 1; i < n; i++) {
        if (p[i] > p[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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