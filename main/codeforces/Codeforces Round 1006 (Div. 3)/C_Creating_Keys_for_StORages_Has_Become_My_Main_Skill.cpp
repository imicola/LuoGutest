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
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << x << endl;
        return;
    }
    int k = -1;
    int p = 0;
    for (size_t i = 0; i < n - 1; i++) {
        p |= i;
        if ((x | p) == x) {
            cout << i << " ";
        }
        else {
            k = i;
            break;
        }
    }
    if (k == -1) {
        if ((p | (n - 1)) != x) {
            cout << x << endl;
            return;
        }
        else {
            cout << n - 1 << endl;
            return;
        }
    }
    for (size_t i = 0; i < n - k - 1; i++) {
        cout << 0 << " ";
    }
    cout << x << endl;
    return;
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