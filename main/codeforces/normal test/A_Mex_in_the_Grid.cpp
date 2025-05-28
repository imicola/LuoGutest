//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// TODO 记得写题解
// 二四译码器的实际应用.jpg
void solve()
{
    int n;
    cin >> n;
    int x = (n + 1) / 2;
    int y = (n + 1) / 2;
    int cnt0 = 0, rx = x + 1, up_y = y, lx = x, under_y = y + 1;
    bool nx = 0, ny = 0;
    vvint vv(n + 1, vint(n + 1, 0));
    while (cnt0 < n * n) {
        vv[y][x] = cnt0;
        cnt0++;
        // cout << ny << " " << nx << " " << y << " " << x << endl;
        if ((!ny) && (!nx) && x < rx) {
            // cout << 1 << " ";
            x++;
            if (x == rx) {
                nx = 1;
                lx--;
                // cout << "PP" << lx << endl;
                continue;
            }
        }
        if ((nx) && (!ny) && y < under_y) {
            y++;
            if (y == under_y) {
                ny = 1;
                up_y--;
                continue;
            }
        }
        if ((ny) && (nx) && x > lx) {
            x--;
            // cout << 3 << " ";
            if (x == lx) {
                nx = 0;
                rx++;
                continue;
            }
        }
        if ((!nx) && (ny) && y > up_y) {
            y--;
            if (y == up_y) {
                ny = 0;
                under_y++;
                continue;
            }
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}