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
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n;
    cin >> n;
    vint a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool l = (a.front() != -1);
    bool r = (a.back() != -1);
    if ((l && r) || (!l && !r)) {
        if (!l) a[0] = 0;
        for (i64 i = 1; i < n; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        i64 ans = a[n - 1] - a[0];
        cout << abs(ans) << endl;
        for (auto &&i : a) cout << i << " ";
        cout << endl;
    }
    else {
        for (i64 i = 0; i < n; i++) {
            if (a[i] == -1) a[i] = 0;
        }
        if (!l && r) {
            a[0] = a[n - 1];
        }
        else if (l && !r) {
            a[n - 1] = a[0];
        }
        cout << 0 << endl;
        for (auto &&i : a) cout << i << " ";
        cout << endl;
    }
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