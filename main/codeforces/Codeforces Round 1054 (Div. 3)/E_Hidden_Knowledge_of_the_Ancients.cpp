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
    i64 n, k, l, r;
    cin >> n >> k >> l >> r;
    vint a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 我们统计最多为k and k - 1 的区间然后相减
    // 做一次容斥差分
    auto f = [&](i64 x, i64 len) -> i64 {
        if (x < 0 || len <= 0) return 0;
        map<i64, i64> freq;
        i64 dis = 0;
        i64 res = 0;
        i64 L = 0;
        for (i64 R = 0; R < n; R++) {
            freq[a[R]]++;
            if (freq[a[R]] == 1) {
                dis++;
            }
            // 保证元素数小于k
            while (dis > x) {
                freq[a[L]]--;
                if (freq[a[L]] == 0) dis--;
                L++;
            }
            // 保证长度小于len
            while (R - L + 1 > len) {
                freq[a[L]]--;
                if (freq[a[L]] == 0) dis--;
                L++;
            }
            // 以R为右端点的合法区间数
            res += R - L + 1;
        }
        return res;
    };

    i64 ans = f(k, r) - f(k, l - 1) - f(k - 1, r) + f(k - 1, l - 1);
    cout << ans << endl;
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