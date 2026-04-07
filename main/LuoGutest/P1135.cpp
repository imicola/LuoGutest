//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n, a, b;
    cin >> n >> a >> b;
    vint v(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    /* 
        从 a -> b，可以上可以下
        求最少的到达按键次数
        一维bfs
    */
    queue<i64> qu;
    qu.push(a);
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    vint path(n + 1, -1);
    path[a] = 0;
    while (!qu.empty()) {
        i64 fl = qu.front();
        i64 diff = v[fl];
        qu.pop();
        if (fl == b) {
            cout << path[fl] << endl;
            return;
        }
        if (fl - diff > 0  && path[fl - diff] == -1) {
            qu.push(fl - diff);
            path[fl - diff] = path[fl] + 1;
        }
        if (fl + diff <= n && path[fl + diff] == -1) {
            qu.push(fl + diff);
            path[fl + diff] = path[fl] + 1;
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}