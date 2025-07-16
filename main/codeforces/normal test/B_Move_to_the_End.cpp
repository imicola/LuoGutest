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
    vint pmax(n);
    vint rsum(n);
    pmax[0] = v[0];
    rsum[0] = v[n - 1];
    for (size_t i = 1; i < n; i++) {
        pmax[i] = max(pmax[i - 1], v[i]);
        rsum[i] = rsum[i - 1] + v[n - 1 - i];
    }
    ranges::reverse(pmax);
    for (size_t i = 0; i < n; i++) {
        cout << max(rsum[i] - v[n - 1 - i] + pmax[i], rsum[i]) << " ";
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