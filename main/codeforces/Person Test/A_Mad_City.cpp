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

/* 
    a如何才无法追上b呢？
    b在被a抓到前跑到一个环里即可
    所以我们的目标是找距离b所有的环对b跑dijk获得环上每一个节点最短路长度dis1
    然后对这些最近点后再跑一次对a的dijk获得dis2
    判断是否存在一个 dis2 < dis1 ? 如果可行则说明方案可行 

    现在最大的问题是如何找到所有的环？
    我们可以先对a，b跑边权为1的全局最短路获得两个最短路
    然后就是怎么找环的所有节点？
    这我真不会
    我们可以通过删去所有度为1的节点，剩下的点一定是环上的点

    复杂度O(4nlog(n) + n)
*/

// vvpii 分装的dijk

const i64 INF = 1e18;
const i64 N = 2e5 + 10;

struct Dijk
{
    int n;
    vector<pair<int, int>> g[N];
    vector<i64> dist;
    vector<int> vis;

    Dijk(int n = 0)
    {
        init(n);
    }
    void init(int n_)
    {
        n = n_;
        for (int i = 1; i <= n; i++) g[i].clear();
        dist.assign(n + 1, INF);
        vis.assign(n + 1, 0);
    }

    void addedge(int u, int v, int w, bool directed = false)
    {
        g[u].push_back({v, w});
        if (!directed) g[v].push_back({u, w});
    }

    void run(int s)
    {
        fill(dist.begin(), dist.end(), INF);
        fill(vis.begin(), vis.end(), 0);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;

            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    i64 getDist(int x) const
    {
        return dist[x];
    }
    vint getdisv() const
    {
        return dist;
    }
};

void solve()
{
    i64 n;
    i64 a, b;
    cin >> n >> a >> b;
    vector<vector<i64>> adj(n + 1);
    Dijk dij(n);

    for (i64 i = 0; i < n; i++) {
        i64 v1, v2;
        cin >> v1 >> v2;
        i64 w = 1;
        // 填充两个结构
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        dij.addedge(v1, v2, w);
    }

    vector<i64> deg(n + 1, 0);
    for (i64 i = 1; i <= n; ++i) {
        deg[i] = adj[i].size();
    }
    queue<i64> q;
    vector<i64> circ(n + 1, 1);
    for (i64 i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            q.push(i);
            circ[i] = 0;
        }
    }
    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        for (i64 v : adj[u]) {
            if (deg[v] <= 0) continue;
            deg[v]--;
            if (deg[v] == 1) {
                circ[v] = 0;
                q.push(v);
            }
        }
        deg[u] = 0;
    }
    dij.run(a);
    vint dis1 = dij.getdisv();
    dij.run(b);
    vint dis2 = dij.getdisv();
    bool ok = false;
    for (i64 v = 1; v <= n; ++v) {
        if (circ[v]) {
            if (dis2[v] < dis1[v]) {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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