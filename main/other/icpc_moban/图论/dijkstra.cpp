//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef pair<i64, int> pii;

// vvpii 分装的dijk

const i64 INF = 1e18;
const int N = 200005; // 根据题目范围调整

struct Dijk
{
    int n;
    vector<pair<int, int>> g[N];
    vint dist;
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
    int n, m, s;
    cin >> n >> m >> s;

    Dijk dij(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dij.addedge(u, v, w, true); // 有向图，若无向图则改为 false
    }

    dij.run(s);

    for (int i = 1; i <= n; i++) {
        if (dij.getDist(i) == INF)
            cout << "INF" << ' ';
        else
            cout << dij.getDist(i) << ' ';
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
