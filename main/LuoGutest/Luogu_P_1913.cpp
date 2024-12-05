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

int n, m;
vector<vector<char>> mpp;
vector<vector<bool>> path;
void sc(int y, int x)
{
    if (y <= n && x <= m) {
        path[y][x] = 1;
        if (mpp[y - 1][x] == 'd') sc(y - 1, x);
        if (mpp[y + 1][x] == 'u') sc(y + 1, x);
        if (mpp[y][x - 1] == 'r') sc(y, x - 1);
        if (mpp[y][x + 1] == 'l') sc(y, x + 1);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    mpp = vector<vector<char>>(n + 2, vector<char>(m + 2, 'o'));
    path = vector<vector<bool>>(n + 2, vector<bool>(m + 2, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> mpp[i][j];
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (mpp[i][j] == 'o') {
                sc(i, j);
            }
        }
    }
    int ans = 0;
    for (auto &&i : path) {
        for (auto &&j : i) {
            if (j) ans++;
        }
    }
    cout << ans;
    return 0;
}