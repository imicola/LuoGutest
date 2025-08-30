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
    ranges::sort(a, greater<int>{});
    int ans = 0;
    // if (n & 1) ans += a[n - 1];
    for (size_t i = 0; i < n; i++) {
        if ((i & 1) == 0) ans += a[i];
    }

    cout << ans << endl;
}
/*
    我们试分析 3 1 4 1 5 9
    排序 1 1 3 4 5 9
    依次选择(9,5),(4,3),(1,1) 得cnt = 14

      
*/
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}