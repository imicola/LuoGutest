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
    int n;
    cin >> n;
    vint a(n + 1);
    int sum = 0;
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (size_t i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            ans += a[i] * n;
            continue;
        }
        int p = ((i - 1) * (n - i + 1) + (n - i + 1));
        ans += p * a[i];
    }
    cout << ans;
}

// 5 8 9 8 5
// 6 10 12 12 10 6
// 7 12 15
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