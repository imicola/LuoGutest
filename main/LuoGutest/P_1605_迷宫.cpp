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

int n, m, t;
int sx, sy, fx, fy;
int cnt = 0;

void bfs(int x, int y, vvint mp)
{
    if (mp[x][y] == 1) return;
    if (x > n || x <= 0 || y > m || y <= 0) return;
    if (x == fx && y == fy) {
        cnt++;
        return;
    }
    mp[x][y] = 1;
    bfs(x + 1, y, mp);
    bfs(x, y + 1, mp);
    bfs(x - 1, y, mp);
    bfs(x, y - 1, mp);
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    vvint mp(n + 2, vint(m + 2, 0));
    for (size_t i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 1;
    }
    bfs(sx, sy, mp);
    cout << cnt;
    return 0;
}