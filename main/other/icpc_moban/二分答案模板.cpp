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
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        auto check = [&]() -> bool {
            /* 检查函数 */
        };
        if (check()) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
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