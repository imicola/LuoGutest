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

/* 
    想让 f(ai) = b
    通过构造a,保证ai <= n
    1 2 3 4 4 4
    6 
*/
void solve()
{
    i64 n;
    cin >> n;
    vint b(n);
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    for (i64 i = 1; i <= n; i++) {
        // 如果元素小于其出现次数,则跳过
        if (mp.contains(i) && (mp[i] < i || mp[i] % i != 0)) {
            cout << -1 << endl;
            return;
        }
    }
    // 构造一个对应数组,其中存放是这个数字的起始可输出数字
    // 
    vint res(n + 1);
    i64 now = 1;
    for (auto &&[i, j] : mp) {
        res[i] = now;
        now += j / i;
    }
    vint cnt(n + 1, 0);
    for (i64 i = 0; i < n; i++) {
        // 输出起始可以输出的数字 + 之前输出过的数字造成的增量
        cout << res[b[i]] + (cnt[b[i]] / b[i]) << " ";
        cnt[b[i]]++;
    }
    cout << endl;
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