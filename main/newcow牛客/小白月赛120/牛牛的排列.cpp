//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    if (n & 1) {
        for (size_t i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else {
        if (n == 2) {
            cout << -1 << endl;
            return;
        }
        cout << "1 2 4 3 ";
        for (size_t i = 5; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
    }
}
// 1 2 4 3 5 6
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}