//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
#define size_t int
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
    int p = ((n * (n + 1)) / 2);
    if ((int)sqrt(p) * (int)sqrt(p) == p) {
        cout << -1 << endl;
        return;
    }
    // int sum = 0;
    vint ans(n);
    for (size_t i = 0; i < n; i++) {
        ans[i] = i + 1;
    }
    for (size_t i = 0; i + 1 < n; i++) {
        int k = ((i + 1) * (i + 2)) / 2;
        if ((int)sqrt(k) * (int)sqrt(k) == k) {
            swap(ans[i], ans[i + 1]);
        }
        // cout << ans[i] << " ";
    }
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