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
    int n, k;
    cin >> n >> k;
    vint a(n), b(n);
    for (auto &&i : a) {
        cin >> i;
    }
    set<int> x;
    for (size_t i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            x.insert(a[i] + b[i]);
        }
    }
    if (x.size() > 1) {
        cout << 0 << endl;
        return;
    }
    if (x.size() == 1) {
        int p = *x.begin();
        for (size_t i = 0; i < n; i++) {
            if (b[i] == -1) {
                int p2 = p - a[i];
                if (p2 > k || p2 < 0) {
                    cout << "0" << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
        return;
    }
    else {
        auto [k1, k2] = ranges::minmax(a);
        cout << (k1 + k - k2 + 1 > 0 ? k1 + k - k2 + 1 : 0) << endl;
    }
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