//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint a(n), b(m);
    for (auto &&i : a) {
        cin >> i;
    }
    for (auto &&i : b) {
        cin >> i;
    }
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    i64 ans = INT_MIN;
    vpii pa, pb;
    auto f = [&](i64 x) -> i64 {
        if (x <= 1) return 0;
        return 64 - __builtin_clzll(x - 1);
    };
    for (size_t i = 0; i  < n; i++) {
        i64 x = a[i];
        i64 cnt = i;
        while (cnt < n && a[i] == a[cnt]) {
            cnt++;
        }
        pa.emplace_back(x, cnt - i);
        i = cnt - 1;
    }
    for (size_t i = 0; i  < m; i++) {
        i64 x = b[i];
        i64 cnt = i;
        while (cnt < m && b[i] == b[cnt]) {
            // i++;
            cnt++;
        }
        pb.emplace_back(x, cnt - i);
        i = cnt - 1;
    }
    
    if (pa.size() != pb.size()) {
        cout << -1 << endl;
        return;
    }
    for (i64 i = 0; i < pa.size(); i++) {
        auto &&[a1, a2] = pa[i];
        auto &&[b1, b2] = pb[i];
        if (a1 != b1) {
            cout << -1 << endl;
            return;
        }
        if (a2 > b2) {
            cout << -1 << endl;
            return;
        }
        i64 need = (b2 + a2 - 1) / (a2);
        i64 t = f(need);
        ans = max(ans, t);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}