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

unordered_map<i64, i64> mp;
i64 f(i64 n)
{
    if (mp.contains(n)) return mp[n];
    if (n < 10) return n * (n + 1) / 2;
    string s = to_string(n);
    i64 d = s.size();
    i64 p = 1;
    for (i64 i = 0; i < d - 1; i++) {
        p *= 10;
    }
    // 第一个数位
    i64 d1 = n / p;
    i64 res = 1;
    res = d1 * f(p - 1)             // 这部分计算 0-99, 100-199, 200-299 中除了最高位之外的数字和
          + (d1 * (d1 - 1) / 2) * p // 这部分计算最高位的和，例如 100-199 的最高位'1'，200-299的最高位'2'
          + d1 * (n % p + 1)        // 这部分计算当前最高位的和,例如 300-345 的最高位'3'
          + f(n % p);               // 这部分计算末尾不完整部分

    mp[n] = res;
    return res;
};

void solve()
{
    i64 k;
    cin >> k;
    i64 sum = 0, d = 1, cnt = 9, pow10 = 1;
    while (1) {
        // 第几个数块
        i64 d_block = d * cnt;
        if (k > d_block) {
            k -= d_block;
            i64 l = pow10, r = pow10 * 10 - 1;
            sum += f(r) - f(l - 1);
            // 更新到下一个块
            d++;
            cnt *= 10;
            pow10 *= 10;
        }
        else
            break;
    }
    i64 num = (k - 1) / d;
    if (num > 0) {
        i64 l = pow10, r = l + num - 1;
        sum += f(r) - f(l - 1);
    }
    i64 last = (k - 1) % d + 1;
    i64 pnum = pow10 + num;
    string pnums = to_string(pnum);
    for (i64 i = 0; i < last; i++) {
        sum += (pnums[i] - '0');
    }
    cout << sum << endl;
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