//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl '\n'
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
    cin >> n;
    vint res(2 * n + 1, -1);
    vint cur(2 * n + 1, 0);
    i64 cnt = 0;
    vint ask(2 * n + 1);
    iota(all(ask), 0);
    for (i64 i = 2; i <= 2 * n; i++) {
        cout << "? " << i - cnt << " ";
        for (i64 j = 1; j <= i; j++) {
            if (res[j] == -1) {
                cout << j << " ";
            }
        }
        cout << endl;
        cout.flush();
        i64 cur1 = 0;
        cin >> cur1;
        // cout << cur1 << endl;
        if (cur1 != 0) {
            res[i] = cur1;
            cnt++;
            ask[i] = -1;
        }
    }

    for (i64 i = 1; i <= 2 * n; i++) {
        if (res[i] != -1) continue;
        cout << "? " << n + 1 << " ";
        cout << i << " ";
        for (i64 k = 1; k <= 2 * n; k++) {
            if (ask[k] == -1) cout << k << " ";
        }
        cout << endl;
        cout.flush();
        i64 cur1 = 0;
        cin >> cur1;
        res[i] = cur1;
    }
    cout << "! ";
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