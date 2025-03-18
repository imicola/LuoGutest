#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
const int INFLL = 1e18;
const int MOD = 1e9 + 7;
//

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, pair<int, int>> mp = {
        {1, {2, 0}}, {2, {0, 2}}, {3, {4, 2}}, {4, {2, 4}}, {5, {0, 6}}, {6, {4, 6}}, {7, {2, 8}}};

    vector<pair<int, int>> dd = {{2, 2}, {-2, 2}, {-2, -2}, {2, -2}};
    
    auto bfs = [&](pair<int, int> pr, pair<int, int> prend) -> int {
        vector vis(5, vector<int>(9, -1));
        // vis.clear();
        queue<pair<int, int>> q;
        auto [i, j] = pr;
        q.push({i, j});
        vis[i][j] = 1;
        auto [enx, eny] = prend;
        while (q.size()) {
            auto cur = q.front();
            auto [x, y] = cur;
            q.pop();
            if (x == enx and y == eny) {
                return vis[x][y];
            }
            for (auto &&[dx, dy] : dd) {
                auto xx = x + dx, yy = y + dy;
                if (xx < 0 or xx >= 5 or yy < 0 or yy >= 9 or vis[xx][yy] != -1) {
                    continue;
                }
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx, yy});
            }
        }
        return 0;
    };

    auto ac = bfs(mp[a], mp[c]);
    auto ad = bfs(mp[a], mp[d]);
    auto bc = bfs(mp[b], mp[c]);
    auto bd = bfs(mp[b], mp[d]);
    cout << min(ac + bd, ad + bc);
}

main()
{
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
        cout << endl;
    }
}