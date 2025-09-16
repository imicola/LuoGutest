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
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    vint pre(n);
    pre[0] = v[0];
    for (i64 i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    for (i64 l = 0; l < n; l++) {
        for (i64 r = l + 1; r < n; r++) {
            i64 a, b, c;
            a = pre[l];
            b = pre[r] - pre[l];
            c = pre[n - 1] - pre[r];
            i64 ok = 0;
            if (a % 3 == b % 3 && b % 3 == c % 3) ok = 1;
            if (a % 3 != b % 3 && a % 3 != c % 3 && b % 3 != c % 3) ok = 1;
            if (ok) {
                cout << l + 1 << " " << r + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
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