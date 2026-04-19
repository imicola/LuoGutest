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
const constexpr i64 MOD = 676767677;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint b(n + 2);
    vint mp(m + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    bool ok = 0;
    b[n + 1] = LLONG_MAX;
    b[0] = LLONG_MAX;
    for (i64 i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        if (b[i] <= b[i - 1] && b[i] <= b[i + 1]) ok = 1;
    }
    if (ok) {
        cout << 0 << endl;
        return;
    }
    i64 ans = 1;
    vint pre(m + 2);
    pre[0] = 0;
    pre[1] = mp[0];
    for (i64 i = 2; i <= m + 1; i++) {
        pre[i] = mp[i - 1] + pre[i - 1];
    }
    for (i64 i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        i64 e = min(b[i - 1], b[i + 1]);
        if (b[i] - 1 == e) {
            ans = (ans * pre[b[i]]) % MOD;
        }
        else {
            ans = (ans * mp[b[i] - 1]) % MOD;
        }
    }
    cout << ans << endl;
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