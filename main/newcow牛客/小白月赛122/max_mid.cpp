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
    i64 n, k;
    cin >> n >> k;
    vint v(n);
    i64 cnt0 = 0, cnt1 = 0;
    for (auto &&i : v) {
        cin >> i;
        if (i == 0) cnt0++;
        if (i == 1) cnt1++;
    }
    if (cnt1 >= k || cnt0 >= k || k - cnt1 < (k + 1) / 2) {
        cout << 0 << endl;
        return;
    }
    else {
        cout << 1 << endl;
        return;
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