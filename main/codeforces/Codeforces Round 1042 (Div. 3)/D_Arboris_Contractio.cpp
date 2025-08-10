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
    vvint g(n + 10);
    for (size_t i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(n == 2){
        cout << 0 << endl;
        return;
    }
    int ans = LLONG_MAX;
    int cnt = 0;
    for (auto &&i : g) {
        if (i.size() == 1) cnt++;
    }
    map<int, int> p;
    for (auto &&i : g) {
        if (i.size() == 1) {
            p[i.front()]++;
        }
    }
    for (auto &&[i, j] : p) {
        ans = min(ans, cnt - j);
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