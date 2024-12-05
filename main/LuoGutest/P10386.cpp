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

vvint mp;
auto paxu = [](int x, int y) {
    int co = 0;
    for (size_t i = 1; i < 5; i++) {
        if (mp[y][i] == mp[y][i + 1]) co++;
    }
    if (co == 4) return 0;
    co = 0;
    for (size_t i = 1; i < 5; i++) {
        if (mp[i][x] == mp[i + 1][x]) co++;
    }
    if (co == 4) return 0;
    if (x == y) {
        co = 0;
        for (size_t i = 1; i < 5; i++) {
            if (mp[i][i] == mp[i + 1][i + 1]) co++;
        }
        if (co == 4) return 0;
        co = 0;
        for (size_t i = 1; i < 5; i++) {
            if (mp[i][6 - i] == mp[i + 1][5 - i]) co++;
        }
        if (co == 4) return 0;
    }
    return 1;
};
int ans = 0;
void dfs(int x, int y, int n)
{
    if (mp[x][y] == -1) return;
    if (n == 24) {
        if (paxu(x, y)) ans++;
    }
    
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    mp = vvint(6, vint(6, -1));
    // w:13 b: 12;
    dfs(1, 1, 1);
    cout << ans;
    return 0;
}