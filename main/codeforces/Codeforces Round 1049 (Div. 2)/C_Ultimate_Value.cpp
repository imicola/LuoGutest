//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define ai64(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long i64;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    vint a(n);
    for (auto &&i : a) cin >> i;
    // if (n & 1) a.emplace_back(0);
    i64 fa = 0;
    for (i64 i = 0; i < n; i++) {
        fa += ((i) & 1 ? -a[i] : a[i]);
    }
    // cout << fa << endl;
    // 我们交换条件是 要么不交换,要么交换一次
    // 交换一次需要最优情况

    // 计算同符号fa不发生变化Max1
    i64 Max1 = 0;

    // 奇数位置
    i64 fodd = -1, lodd = -1;
    for (i64 i = 0; i < n; i += 2) {
        if (fodd == -1) fodd = i;
        lodd = i;
    }
    // 奇数可以构成的最大值
    if (fodd != -1 && lodd != -1) {
        Max1 = max(Max1, lodd - fodd);
    }
    // 偶数位置
    i64 fev = -1, lev = -1;
    for (i64 i = 1; i < n; i += 2) {
        if (fev == -1) fev = i;
        lev = i;
    }
    //
    if (fev != -1 && lev != -1) {
        Max1 = max(Max1, lev - fev);
    }

    i64 Max2 = LLONG_MIN;
    i64 Minodd = LLONG_MAX;

    // 当i % 2 && j%2 != 0时候,fa2 = fa + 2(a[j] - a[i]) + (j - i)
    // 2a[j] - 2a[i] + j - l 
    for (i64 j = 0; j < n; j++) {
        if (j % 2 == 1) {
            i64 val_j = 2 * a[j] + j;
            if (Minodd != LLONG_MAX) Max2 = max(Max2, val_j - Minodd);
        }
        else {
            i64 val_j = 2 * a[j] + j;
            if (val_j < Minodd) Minodd = val_j;
        }
    }
    // 反之
    i64 Max3 = LLONG_MIN;
    i64 Mineven = LLONG_MAX;
    for (i64 j = 0; j < n; j++) {
        if (j % 2 == 0) {
            i64 val_j = 2 * a[j] - j;
            if (Mineven != LLONG_MAX) Max3 = max(Max3, Mineven - val_j);
        }
        else {
            i64 val_j = 2 * a[j] - j;
            if (val_j > Mineven) Mineven = val_j;
        }
    }

    if (Max2 != LLONG_MAX) Max1 = max(Max1, Max2);
    if (Max3 != LLONG_MAX) Max1 = max(Max1, Max3);

    cout << fa + max(0ll, Max1) << endl;
}
/* 
4
7 1 8 4
f(a1) = 10


*/
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