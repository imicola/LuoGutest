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
    i64 p, q;
    cin >> p >> q;
    i64 k = p + 2 * q;
    // 苏达拉姆筛法
    i64 x = 2 * k + 1;
    // 拆出x的所有约数对,除去1和x
    auto factors = [](i64 x) {
        vpii res;
        for (i64 i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                res.emplace_back(i, x / i);
            }
        }
        return res;
    };
    auto v = factors(x);
    for (auto &&[a, b] : v) {
        i64 k1 = (a - 1) / 2;
        i64 k2 = (b - 1) / 2;
        if (abs(k1 - k2) <= p) {
            cout << k1 << ' ' << k2 << endl;
            return;
        }
    }
    cout << -1 << endl;
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