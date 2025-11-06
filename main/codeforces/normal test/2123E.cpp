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
    map<i64, i64> freq;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    vint diff(n + 2);
    for (i64 i = 0; i <= n; i++) {
        diff[freq[i]]++;
        diff[n - i + 1]--;
        if (!freq[i]) break;
    }
    vint ans(n + 2, 0);
    for (i64 i = 0; i <= n; i++) {
        ans[i] = diff[i];
        if (i != 0) {
            ans[i] += ans[i - 1];
        }
    }
    for (i64 i = 0; i <= n; i++) {
        cout << ans[i] << " ";
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