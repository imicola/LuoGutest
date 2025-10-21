//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint c(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> c[i];
    }
    vvint g(n + 1);
    for (i64 i = 0; i < n - 1; i++) {
        i64 u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    i64 LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<int> parent(n + 1, 0), depth(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    int root = 1;
    vvint children(n + 1);
    vector<int> st;
    st.push_back(root);
    parent[root] = 0;
    depth[root] = 0;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        order.push_back(u);
        for (auto &vv : g[u]) {
            if (vv != parent[u]) {
                int v = (int)vv;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                children[u].push_back(v);
                st.push_back(v);
            }
        }
    }
    order.clear();
    vector<int> stk;
    stk.reserve(n);
    stk.push_back(root);
    vector<int> it_idx(n + 1, 0);
    while (!stk.empty()) {
        int u = stk.back();
        if (it_idx[u] < (int)children[u].size()) {
            int v = children[u][it_idx[u]++];
            stk.push_back(v);
        }
        else {
            order.push_back(u);
            stk.pop_back();
        }
    }
    const i64 INF = (i64)9e18;
    vint dp(n + 1, INF);
    for (int uu : order) {
        int u = uu;
        if (children[u].empty()) {
            dp[u] = c[u];
        }
        else {
            i64 min1 = INF, min2 = INF;
            for (int v : children[u]) {
                i64 val = dp[v];
                if (val < min1) {
                    min2 = min1;
                    min1 = val;
                }
                else if (val < min2)
                    min2 = val;
            }
            i64 combine = (min1 == INF || min2 == INF) ? INF : (min1 + min2);
            dp[u] = min(c[u], combine);
        }
    }
    vint edgeW(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        if (children[u].empty()) continue;
        i64 min1 = INF, min2 = INF;
        int argmin = -1;
        for (int v : children[u]) {
            i64 val = dp[v];
            if (val < min1) {
                min2 = min1;
                min1 = val;
                argmin = v;
            }
            else if (val < min2)
                min2 = val;
        }
        for (int v : children[u]) {
            if (v == argmin)
                edgeW[v] = (min2 >= INF ? INF : min2);
            else
                edgeW[v] = (min1 >= INF ? INF : min1);
            if (edgeW[v] >= INF / 2) edgeW[v] = INF;
        }
    }

    vvint up(LOG, vint(n + 1, 0));
    vvint sumUp(LOG, vint(n + 1, 0));
    for (int v = 1; v <= n; ++v) {
        up[0][v] = parent[v];
        sumUp[0][v] = (parent[v] == 0 ? 0 : edgeW[v]);
    }
    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            int mid = up[k - 1][v];
            up[k][v] = (mid == 0 ? 0 : up[k - 1][mid]);
            if (mid == 0)
                sumUp[k][v] = sumUp[k - 1][v];
            else {
                i64 s = sumUp[k - 1][v];
                if (sumUp[k - 1][mid] >= INF || s >= INF)
                    sumUp[k][v] = INF;
                else {
                    sumUp[k][v] = s + sumUp[k - 1][mid];
                    if (sumUp[k][v] > INF) sumUp[k][v] = INF;
                }
            }
        }
    }
    vint tin(n + 1), tout(n + 1);
    int timer = 0;
    {
        vint stk;
        vint it_idx(n + 1, 0);
        stk.push_back(root);
        while (!stk.empty()) {
            i64 u = stk.back();
            if (it_idx[u] == 0) tin[u] = ++timer;
            if (it_idx[u] < children[u].size()) {
                i64 v = children[u][it_idx[u]++];
                stk.push_back(v);
            }
            else {
                tout[u] = ++timer;
                stk.pop_back();
            }
        }
    }
    auto is_ancestor = [&](int a, int b) -> bool { return tin[a] <= tin[b] && tout[b] <= tout[a]; };
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (!is_ancestor(y, x)) {
            cout << -1 << '\n';
            continue;
        }
        if (x == y) {
            cout << 0 << '\n';
            continue;
        }
        i64 ans = 0;
        int diff = depth[x] - depth[y];
        int cur = x;
        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k)) {
                if (sumUp[k][cur] >= INF) {
                    ans = INF;
                    break;
                }
                ans += sumUp[k][cur];
                if (ans >= INF) {
                    ans = INF;
                    break;
                }
                cur = up[k][cur];
            }
        }
        if (ans >= INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}