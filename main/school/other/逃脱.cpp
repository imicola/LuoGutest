//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m, '0'));
    pii index_S, index_E, index_F;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'E') index_E = make_pair(i, j);
            if (mp[i][j] == 'S') index_S = make_pair(i, j);
            if (mp[i][j] == '*') index_F = make_pair(i, j);
        }
    }
    vvint path(n, vint(m, 0));
    vvint path2(n, vint(m, 0));
    queue<pii> qu, qu2;
    qu.emplace(index_S);
    qu2.emplace(index_F);
    vint gox = {1, -1, 0, 0};
    vint goy = {0, 0, 1, -1};
    int rx = 0, rf = 0;
    while (!qu.empty()) {
        auto [i, j] = qu.front();
        if (qu.front() == index_E && mp[i][j] == 'E') {
            rx = path[i][j];
            break;
        }
        qu.pop();
        for (size_t index = 0; index < 4; index++) {
            int i2 = i + gox[index];
            int j2 = j + goy[index];
            if (i + gox[index] < 0 || i + gox[index] >= m || j + goy[index] < 0 || j + goy[index] > n) continue;
            if (mp[i + gox[index]][j + goy[index]] == '#') continue;
            path[i2][j2] = path[i][j] + 1;
            qu.emplace(i2, j2);
        }
    }
    while (!qu2.empty()) {
        auto [fi, fj] = qu2.front();
        if (qu2.front() == index_E && mp[fi][fj] == 'E') {
            rf = path2[fi][fj];
            break;
        }
        qu2.pop();
        for (size_t index = 0; index < 4; index++) {
            int i2 = fi + gox[index];
            int j2 = fj + goy[index];
            if (fi + gox[index] < 0 || fi + gox[index] >= m || fj + goy[index] < 0 || fj + goy[index] > n) continue;
            if (mp[fi + gox[index]][fj + goy[index]] == '#') continue;
            // mp[i2][j2] = '#';
            path2[i2][j2] = path2[fi][fj] + 1;
            qu2.emplace(i2, j2);
        }
    }
    cout << rx << " " << rf;
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