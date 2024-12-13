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

vint dy = {1, 2, -2, -1, -1, -2, 1, 2};
vint dx = {2, 1, -1, -2, 2, 1, -2, -1};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vvint mp(n + 10, vint(m + 10, -1));
    vvint vis(n + 10, vint(m + 10, 0));
    queue<pii> q;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    mp[x][y] = 0;
    while (!q.empty()) {
        int xk = q.front().first;
        int yk = q.front().second;
        q.pop();
        for (size_t i = 0; i < 8; i++) {
            int t1 = xk + dx[i];
            int t2 = yk + dy[i];
            if (t1 > n || t2 > m || t1 <= 0 || t2 <= 0 || vis[t1][t2] == 1) continue;
            mp[t1][t2] = mp[xk][yk] + 1;
            vis[t1][t2] = 1;
            q.push(make_pair(t1, t2));
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            printf("%-5d", mp[i][j]);
        }
        cout << endl;
    }
}

/*
0040200
0300020
000X000
0200020
0020100
*/
// mp[y + 2][x + 1] = k + 1;
// mp[y + 1][x + 2] = k + 1;
// mp[y - 1][x - 2] = k + 1;
// mp[y - 2][x - 1] = k + 1;
// mp[y + 2][x - 1] = k + 1;
// mp[y + 1][x - 2] = k + 1;
// mp[y - 2][x + 1] = k + 1;
// mp[y - 1][x + 2] = k + 1;