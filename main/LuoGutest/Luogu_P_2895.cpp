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

const vint stockx = {0, 1, -1, 0, 0};
const vint stocky = {0, 0, 0, 1, -1};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vvint mapp(310, vint(310, 1e6));
    for (size_t i = 0; i < t; i++) {
        int x, y, T;
        cin >> x >> y >> T;
        x += 1;
        y += 1;
        for (size_t i = 0; i < 5; i++) {
            mapp[y + stocky[i]][x + stockx[i]] = min(T, mapp[y + stocky[i]][x + stockx[i]]);
        }
    }
    queue<pii> qu;
    vvint path(310, vint(310, 0));
    qu.emplace(1, 1);
    path[1][1] = 0;
    int kt = 0;
    while (!qu.empty()) {
        int y1 = qu.front().first;
        int x1 = qu.front().second;
        if (mapp[y1][x1] == 1e6) {
            cout << path[y1][x1];
            return 0;
        }
        qu.pop();
        for (size_t i = 1; i < 5; i++) {
            int x2 = x1 + stockx[i];
            int y2 = y1 + stocky[i];
            if (y2 > 0 && x2 > 0 && path[y2][x2] == 0) {
                if (mapp[y2][x2] > path[y1][x1] + 1) {
                    qu.emplace(y2, x2);
                    path[y2][x2] = path[y1][x1] + 1;
                }
            }
        }
    }
    cout << -1;
    return 0;
}