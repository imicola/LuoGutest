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

/* 
n = 12可以尝试枚举所有情况

如何枚举？
全排列枚举?

*/

void solve()
{
    i64 n;
    cin >> n;
    vint x(n + 1), y(n + 1), next(n + 1);
    vint res(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            if (x[i] < x[j] && y[i] == y[j]) {
                if (next[i] == 0 || x[j] < x[next[i]]) {
                    next[i] = j;
                }
            }
        }
    }
    auto check = [&]() -> bool {
        for (i64 i = 1; i <= n; i++) {
            i64 curr = i;
            for (i64 j = 0; j < n; j++) {
                curr = next[res[curr]];
                if (curr == 0) break;
            }
            if (curr != 0) return 1;
        }
        return 0;
    };
    auto dfs = [&](auto &&self) -> i64 {
        i64 i;
        for (i = 1; i <= n; i++) {
            if (res[i] == 0) break;
        }
        if (i > n) {
            return check() ? 1 : 0;
        }
        i64 cnt = 0;
        for (i64 j = i + 1; j <= n; j++) {
            if (res[j] == 0) {
                res[i] = j;
                res[j] = i;
                cnt += self(self);
                res[i] = res[j] = 0;
            }
        }
        return cnt;
    };
    cout << dfs(dfs) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}