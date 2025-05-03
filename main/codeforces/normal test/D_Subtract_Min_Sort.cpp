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
    if (ranges::is_sorted(v)) {
        cout << "YES" << endl;
        return;
    }
    auto ci = [&](int i) {
        int p = min(v[i], v[i + 1]);
        v[i] -= p;
        v[i + 1] -= p;
    };
    for (size_t i = 0; i + 1 < n; i++) {
        ci(i);
    }
    cout << (ranges::is_sorted(v) ? "YES" : "NO") << endl;
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