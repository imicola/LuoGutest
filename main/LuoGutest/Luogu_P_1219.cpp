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

int p;
vvint mp;
// vvint path;

void srachp(int x, int y, int n, int &out_return)
{
    if (mp[y][x] != 0 || x >= p || y >= p) return;
    if (n == 6) {
        out_return = 1;
        return;
    }
    for (size_t i = 1; i <= p; i++) {
        mp[i][x] = 1;
        mp[y][i] = 1;
    }
    mp[y][x] = 2;
    for (size_t i = 1; x + i <= p && y + i <= p; i++) mp[y + i][x + i] = 1;
    for (size_t i = 1; x - i >= 1 && y - i >= 1; i++) mp[y - i][x - i] = 1;
    for (size_t i = 1; y + i <= p && x - i >= 1; i++) mp[y + i][x - i] = 1;
    for (size_t i = 1;y - i >= 1 && x + i <= p ; i++) mp[y - i][x + i] = 1;

    for (size_t i = y; i <= p; i++) {
        for (size_t j = 1; j <= p; j++) {
            if (i == y && j <= x) continue;
            srachp(j, i, n++, out_return);
            // for (auto &&ii : mp) {
            //     for (auto &&tt : ii) {
            //         cout << tt;
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> p;
    // path = vvint(n + 2, vint(n + 2, 0));
    int ans = 0;
    for (size_t i = 1; i <= p; i++) {
        for (size_t j = 1; j <= p; j++) {
            mp = vvint(p + 2, vint(p + 2, 0));
            int res = 0;
            srachp(j, i, 1, res);
            // for (auto &&ii : mp) {
            //     for (auto &&tt : ii) {
            //         cout << tt;
            //     }
            //     cout << endl;
            // }
            // cout << endl;
            ans += res;
        }
    }
    cout << ans;
    return 0;
}