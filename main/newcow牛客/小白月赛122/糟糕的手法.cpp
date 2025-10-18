//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint v(n);
    // cnt1表示正数
    i64 cnt1 = 0, cnt2 = 0, cnt0 = 0;
    for (auto &&i : v) {
        cin >> i;
        if (i > 0) cnt1++;
        if (i < 0) cnt2++;
        if (i == 0) cnt0++;
    }
    // 一个负数可以将正数变成负数，也可以将一个负数变成正数
    // 负数的极限是构造出 n - 1个负数，即一定有一个负数无法变成正数
    if (m == cnt1) {
        cout << 0 << endl;
        return;
    }
    if (m > cnt1) {
        if (m >= n - cnt0) {
            cout << -1 << endl;
            return;
        }
        cout << abs(m - cnt1) << endl;
    }
    if (m < cnt1) {
        if (cnt2 == 0) {
            if (cnt0 == 0)
                cout << -1 << endl;
            else {
                cout << abs(m - cnt1) << endl;
            }
            return;
        }
        else {
            cout << abs(m - cnt1) << endl;
        }
    }
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