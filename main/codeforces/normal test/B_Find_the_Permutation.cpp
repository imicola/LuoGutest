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

void solve()
{
    //TODO:题解
    int n;
    cin >> n;
    vvint mp(n + 1, vint(n + 1, 0));
    char t;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cin >> t;
            mp[i][j] = (t ^ 48);
        }
    }
    vint ans(n);
    ranges::iota(ans, 1);
    ranges::sort(ans, [&](int a, int b) {
        if (mp[a][b] == 1) return a < b;
        return a > b;
    });
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
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