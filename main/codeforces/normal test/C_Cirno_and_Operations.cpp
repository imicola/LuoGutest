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
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    int ans = accumulate(all(v), 0);
    vint cur = v; //构造差序对数组
    for (size_t i = 1; i < n; i++) {
        int m = cur.size();
        int sum = 0;
        vector<int> nxt(m - 1); // 下一个差序对数组
        for (size_t k = 0; k + 1 < m; k++) {
            nxt[k] = cur[k + 1] - cur[k];
            sum += nxt[k];
        }
        ans = max(ans, abs(sum));
        cur.swap(nxt);
    }
    cout << ans << endl;
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