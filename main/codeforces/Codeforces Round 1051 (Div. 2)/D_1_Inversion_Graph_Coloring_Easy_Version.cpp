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
constexpr i64 MOD = 1e9 + 7;
i64 ans = 0;

void dfs(vint &a, vint &path, i64 idx)
{
    if (idx == a.size()) {
        i64 sz = path.size();
        if (sz < 3) {
            ans = (ans + 1) % MOD;
            return;
        }
        vint pre(sz), suf(sz);
        pre[0] = path[0];
        for (i64 i = 1; i < sz; ++i) pre[i] = max(pre[i - 1], path[i]);
        suf[sz - 1] = path[sz - 1];
        for (i64 i = sz - 2; i >= 0; --i) suf[i] = min(suf[i + 1], path[i]);
        bool bad = 0;
        for (i64 j = 1; j + 1 < sz; ++j) {
            if (pre[j - 1] > path[j] && path[j] > suf[j + 1]) {
                bad = 1;
                break;
            }
        }
        if (!bad) ans = (ans + 1) % MOD;
        return;
    }
    dfs(a, path, idx + 1);
    path.push_back(a[idx]);
    dfs(a, path, idx + 1);
    path.pop_back();
}

void solve()
{
    i64 n;
    cin >> n;
    vint a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    vint path;
    vint res;
    dfs(a, path, 0);
    cout << ans % MOD << endl;
    ans = 0;
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