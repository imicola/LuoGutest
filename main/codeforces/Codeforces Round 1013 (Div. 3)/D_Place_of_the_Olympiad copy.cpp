//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
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
    int n, m, k;
    cin >> n >> m >> k;
    int p = ((k + n - 1) / n);
    double q = m / 2;
    if (q >= p) {
        cout << 1 << endl;
        return;
    }
    cout << ((p + (m - p + 1) - 1) / (m - p + 1)) << endl;
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}