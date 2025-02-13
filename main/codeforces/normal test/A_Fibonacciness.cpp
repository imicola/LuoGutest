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
    vint a(6);
    for (size_t i = 1; i <= 5; i++) {
        if (i != 3) cin >> a[i];
    }
    int res = 0;
    for (size_t j = -200; j <= 200; j++) {
        a[3] = j;
        int ans = 0;
        for (size_t i = 1; i + 2 <= 5; i++) {
            if (a[i] + a[i + 1] == a[i + 2]) {
                ans++;
            }
        }
        res = max(res, ans);
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