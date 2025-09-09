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
    char a1, b1;
    scanf("%c-%c", &a1, &b1);
    i64 a = a1 ^ 48, b = b1 ^ 48;
    if (b < 8) {
        cout << a << "-" << b + 1;
        return;
    }
    if (b == 8) {
        cout << a + 1 << "-" << 1;
    }
}
signed main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}