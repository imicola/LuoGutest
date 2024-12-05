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

int n, m, ans = 0;
vector<vector<char>> mpp;
// vvint path;

void cfind(int y, int x, int y_0, int x_0)
{
    // if (path[y][x] != -1) {
    //     if (path[y][x] == 0) {
    //         return;
    //     }
    //     else {
    //         ans++;
    //         return;
    //     }
    // }
    if (mpp[y][x] == 'o') {
        if (x > m || y > n) {
            // path[y_0][x_0] = 0
        }
        else {
            // path[y_0][x_0] = 1;
            ans++;
        }
    }
    if (mpp[y][x] == 'r') {
        cfind(y, x + 1, y_0, x_0);
    }
    if (mpp[y][x] == 'u') {
        cfind(y - 1, x, y_0, x_0);
    }
    if (mpp[y][x] == 'd') {
        cfind(y + 1, x, y_0, x_0);
    }
    if (mpp[y][x] == 'l') {
        cfind(y, x - 1, y_0, x_0);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    mpp = vector<vector<char>>(n + 2, vector<char>(m + 2, 'o'));
    // path = vvint(n + 2, vint(m + 2, -1));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> mpp[i][j];
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cfind(i, j, i, j);
        }
    }
    cout << ans;
    return 0;
}