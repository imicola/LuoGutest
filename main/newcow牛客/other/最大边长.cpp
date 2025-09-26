//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    i64 ans1 = -1, ans2 = -1, ans3 = -1;
    if (a / 3 <= b) ans1 = a / 3;
    ans2 = b / 2;
    if (a >= b * 3) ans3 = b;
    cout << max({ans2, ans1, ans3}) << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}