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

vint result;
vvint path;
vint path2;
int n, m, sum = -1e4,maxx = 0;
void dfs(int pa)
{
    for (size_t i = 1; i <= n; i++) {
        if (path[pa][i] != 0 && path2[i] != 1) {
            path2[i] = 1;
            sum += path[pa][i];
            dfs(i);
            sum -= path[pa][i];
        }
    }
    maxx = max(maxx, sum);
    path2[pa] = 0;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    path = vvint(m + 10, vint(n + 10, 0));
    for (size_t i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = c;
    }
    int ans = 0;
    for (size_t i = 1; i <= n; i++) {
        path2 = vint(n+10, 0);
        path2[i] = 1;
        dfs(i);
    }
    cout << maxx;
    return 0;
}