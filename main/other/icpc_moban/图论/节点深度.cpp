//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

void solve() {
    i64 n;
    cin >> n;
    vvint g(n + 1);
    for (i64 i = 2; i <= n; i++) {
        i64 par = 0;
        cin >> par;
        g[par].emplace_back(i);
    }
    vint deep(n + 1, 1);
    auto dfs = [&](auto &&self, i64 p, i64 c) -> void {
        if (p != -1) deep[c] = deep[p] + 1;
        for (auto &&v : g[c]) {
            if (v == c) continue;
            self(self, c, v);
        }
    };
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}