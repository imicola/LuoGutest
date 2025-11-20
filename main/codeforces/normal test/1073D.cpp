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
    i64 n, t;
    cin >> n >> t;
    vint v(n);
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    i64 ans = 0;
    i64 Min = *min_element(all(v));
    while (t >= Min) {
        i64 sum = 0;
        i64 cnt = 0;
        for (auto &&i : v) {
            if (i <= t) {
                sum += i;
                cnt++;
            }
        }
        if (cnt == 0) break;
        if (sum > t) {
            for (auto &&i : v) {
                if (i <= t) {
                    t -= i;
                    ans++;
                }
            }
        }
        else {
            i64 k = t / sum;
            t -= k * sum;
            ans += k * cnt;
        }
    }

    cout << ans << endl;
}

/* 
    这个问题在于并非按最优方式购买，可能会存在浪费的情况
    如果当前比sum大，则意味一定可以跑完完整的一次
    否则肯定无法跑完最大的
*/
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
