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
vector<vector<int>> mp;

int finds(int y, int x)
{
    if (mp[y - 1][x] == -1 || mp[y + 1][x] == -1 || mp[y][x + 1] == -1 || mp[y][x - 1] == -1) return -1;
    int lenx = 0, leny = 0;
    while (mp[y][x + lenx] == 1 && x + lenx <= m) lenx++;
    while (mp[y + leny][x] == 1 && y + leny <= n) leny++;
    for (size_t i = 0; i < leny; i++) {
        if (mp[y + i][x - 1] == 1) return -1;
        for (size_t j = 0; j < lenx; j++) {
            if (mp[y + i][x + j] != 1) {
                return -1;
            }
            mp[y + i][x + j] = -1;
        }
        if (mp[y + i][x + lenx] == 1) {
            return -1;
        }
    }
    return 1;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    mp = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    // path = vvint(n + 2, vint(m + 2, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '.')
                mp[i][j] = 0;
            else
                mp[i][j] = 1;
        }
    }
    int ans = 0;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (mp[i][j] == 1) {
                int temp = finds(i, j);
                if (temp == -1) {
                    cout << "Bad placement.";
                    return 0;
                }
                ans += temp;
            }
        }
    }
    printf("There are %d ships.", ans);
    return 0;
}