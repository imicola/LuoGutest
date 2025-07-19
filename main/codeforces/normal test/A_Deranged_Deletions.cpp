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
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    vint vv = a;
    ranges::sort(a);
    vint res;
    for (size_t i = 0; i < n; i++) {
        if (vv[i] != a[i]) {
            res.emplace_back(vv[i]);
        }
    }
    if (res.empty()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << res.size() << endl;
    for (auto &&i : res) {
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