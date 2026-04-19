//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n, c, k;
    cin >> n >> c >> k;
    vint v(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    for (i64 i = 1; i <= n; i++) {
        if (v[i] > c) {
            break;
        }
        if (k >= c) {
            k -= (c - v[i]);
            c += c;
        }
        else {
            if (k + v[i] <= c) {
                c += k + v[i];
                k = 0;
            }
            else {
                k = (k + v[i] - c);
                c += c;
            }
        }
    }
    cout << c << endl;
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