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
    vint v(n + 1);
    vvint g(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (i64 i = 0; i < n - 1; i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    /* 
        将所有通向根节点的路径找出来然后dp?
        报告长官，这太难了
        当我们到达某一个点的时候，我们可以选择这个点，或者用这个点减去父节点可能的最小值
    */
    vint Max(n + 1);
    vint Min(n + 1);
    Max[1] = v[1];
    Min[1] = v[1];
    auto dfs = [&](auto &&self, i64 p, i64 idx) -> void {
        if (p != -1) {
            Max[idx] = max(v[idx], v[idx] - Min[p]);
            Min[idx] = min(v[idx], v[idx] - Max[p]);
        }
        for (auto &&c : g[idx]) {
            if (c == p) continue;
            self(self, idx, c);
        }
    };
    dfs(dfs, -1, 1);
    for (i64 i = 1; i <= n; i++) {
        cout << Max[i] << " ";
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