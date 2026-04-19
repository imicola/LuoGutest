//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl '\n'
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
    i64 n;
    cin >> n;
    auto ask = [&](i64 i, i64 j) { cout << "? " << i << " " << j << endl; };
    auto ans = [&](i64 i) { cout << "! " << i << endl; };
    for (i64 i = 1; i <= 2 * n - 2; i += 2) {
        ask(i, i + 1);
        i64 res = 0;
        cin >> res;
        if (res == 1) {
            ans(i);
            return;
        }
    }
    ask(1, 2 * n - 1);
    i64 res = 0;
    cin >> res;
    if (res == 1) {
        ans(1);
        return;
    }
    ask(2, 2 * n - 1);
    cin >> res;
    if (res == 1) {
        ans(2);
        return;
    }
    ans(2 * n);
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}