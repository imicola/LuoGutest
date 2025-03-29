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
    int n, m, k;
    cin >> n >> m >> k;
    int l = 1, r = m, res = 0;
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        auto check = [&]() -> bool {
            int ans = 0;
            int c1 = m / (mid + 1);
            int c2 = m - c1 * (mid + 1);
            ans = c1 * mid + c2;
            return n * ans >= k;
        };
        if (check()) {
            r = (res = mid) - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << endl;
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