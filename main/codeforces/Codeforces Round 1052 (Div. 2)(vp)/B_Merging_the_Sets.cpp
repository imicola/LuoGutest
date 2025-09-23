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
    i64 n, m;
    cin >> n >> m;
    // 1 - m 每个数字进行数据溯源
    vvint path(m + 1);
    vvint vpath(n + 1);
    set<i64> st;
    for (i64 i = 1; i <= n; i++) {
        i64 l;
        cin >> l;
        vpath[i].resize(l);
        for (i64 j = 0; j < l; j++) {
            i64 x;
            cin >> x;
            vpath[i][j] = x;
            path[x].emplace_back(i);
            st.insert(x);
        }
    }
    if (st.size() != m) {
        cout << "NO" << endl;
        return;
    }
    i64 ok = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 lenc = LLONG_MAX;
        for (auto &&k : vpath[i]) {
            i64 len = path[k].size();
            lenc = min(len, lenc);
        }
        if (lenc == 0) {
            cout << "NO" << endl;
            return;
        }
        if (lenc >= 2) ok++;
    }
    cout << (ok >= 2 ? "YES" : "NO") << endl;
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