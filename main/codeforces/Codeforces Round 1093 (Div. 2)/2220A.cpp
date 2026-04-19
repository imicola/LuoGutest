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
    i64 n;
    cin >> n;
    vint v(n);
    set<i64> st;
    i64 ok = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        if (st.contains(v[i])) {
            ok = 1;
        }
        st.insert(v[i]);
    }
    if (ok) {
        cout << -1 << endl;
        return;
    }
    sort(all(v), greater<>{});
    for (auto &&i : v) {
        cout << i << ' ';
    }
    cout << endl;
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