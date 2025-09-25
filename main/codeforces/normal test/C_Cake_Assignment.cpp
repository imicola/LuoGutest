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
    i64 k, x;
    cin >> k >> x;
    i64 have = (1ll << k);
    i64 sum = have * 2;
    i64 b = sum - x;
    i64 cnt = 0;
    vint res;
    while (x != have) {
        if (x * 2 > sum) {
            x -= b;
            b *= 2;
            res.emplace_back(2);
        }
        else if (x * 2 < sum) {
            b -= x;
            x *= 2;
            res.emplace_back(1);
        }
    }
    ranges::reverse(res);
    cout << res.size() << endl;
    for (auto &&i : res) {
        cout << i << " ";
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