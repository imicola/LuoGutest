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

const vint x_ = {1, -1, 0, 0, 1, 1, -1, -1};
const vint y_ = {0, 0, 1, -1, 1, -1, -1, 1};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n = 0, m = 0;
    int y = 0, x = 0;
    cin >> n >> m >> y >> x;
    vvint mp(n + 2, vint(m + 2, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    for (size_t i = 0; i < 8; i++) {
        ans += mp[y + y_[i] + 1][x + x_[i] + 1];
    }
    cout << ans;
    return 0;
}