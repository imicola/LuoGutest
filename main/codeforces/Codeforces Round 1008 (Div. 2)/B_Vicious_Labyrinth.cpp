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
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0) {
        for (size_t i = 0; i < n - 2; i++) {
            cout << n - 1 << " ";
        }
        cout << n << " ";
        cout << n - 1 << endl;
    }
    else {
        for (size_t i = 0; i < n - 1; i++) {
            cout << n << " ";
        }
        cout << n - 1 << endl;
    }
}
// 1 2 3 4
// 3 3 4 3
// 4 4 3 4

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