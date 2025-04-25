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
    int n, x;
    cin >> n >> x;
    if (x >= n) {
        for (size_t i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (size_t i = 0; i < x; i++) {
        cout << i << " ";
    }
    for (size_t j = x + 1; j < n; j++) {
        cout << j << " ";
    }
    cout << x << endl;
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