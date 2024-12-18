//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vint to;
    vint path;
    to = vint(n + 1);
    path = vint(n + 1, -1);
    for (size_t i = 1; i <= n; i++) {
        cin >> to[i];
    }
    queue<int> bfs;
    int ans = 0;
    bfs.push(a);
    path[a] = 0;
    while (!bfs.empty()) {
        int flag = 0;
        int up = bfs.front() + to[bfs.front()];
        int down = bfs.front() - to[bfs.front()];
        if (up > 0 && up <= n && path[up] == -1) {
            path[up] = path[bfs.front()] + 1;
            bfs.push(up);
        }
        if (down > 0 && down <= n && path[down] == -1) {
            path[down] = path[bfs.front()] + 1;
            bfs.push(down);
        }
        bfs.pop();
    }
    cout << path[b];
    return 0;
}