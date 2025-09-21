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
    i64 a, b;
    cin >> a >> b;
    if (b == 1) {
        if (a & 1) {
            cout << a + b << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    if (b & 1) {
        if (a & 1) {
            cout << a * b + 1 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    else {
        i64 p = b;
        i64 pow2 = 0;
        while (b % 2 == 0) {
            b /= 2;
            pow2++;
        }
        if (pow2 > 1) {
            // if (a == 1) {
            //     cout << 2 + p / 2 << endl;
            //     return;
            // }
            cout << a * p / 2 + 2 << endl;
            return;
        }
        else {
            if (a & 1) {
                cout << -1 << endl;
                return;
            }
            else {
                cout << a * (p / 2) + 2 << endl;
                return;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(0);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}