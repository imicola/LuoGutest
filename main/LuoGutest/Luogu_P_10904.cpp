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
    int n, m;
    cin >> n >> m;
    vint l(1e7, 0), r(1e7, 0);
    int tag = 0;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp > 0) {
            r[temp]++;
        }
        else if (temp < 0) {
            l[-temp]++;
        }
        else if (temp == 0) {
            tag++;
        }
    }
    for (size_t i = 1; i <= m; i++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    int ans = 0;
    for (size_t i = 1; i <= m; i++) {
        int x = l[i];
        if (m - i * 2 > 0) {
            x += r[m - i * 2];
        }
        ans = max(ans, x);
        x = r[i];
        if (m - i * 2 > 0) {
            x += l[m - i * 2];
        }
        ans = max(ans, x);
    }
    cout << ans + tag << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}