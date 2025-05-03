//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
//#define size_t int
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
    int p = x;
    int cnt = 0;
    if (n == 1 && x == 0) {
        cout << -1 << endl;
        return;
    }
    if (x == 0) {
        if (n % 2 == 0)
            cout << n << endl;
        else {
            cout << 5 + (n - 2) << endl;
        }
        return;
    }
    if (x == 1) {
        if (n % 2 != 0) {
            cout << n << endl;
        }
        else {
            cout << (n - 2) + 5 << endl;
        }
        return;
    }
    while (p > 0) {
        if ((p & 1) == 1) cnt++;
        p >>= 1;
    }
    if (n < cnt) {
        cout << x << endl;
        return;
    }
    if ((n - cnt) % 2 == 0) {
        cout << x + (n - cnt) << endl;
    }
    else {
        cout << x + n - cnt + 1 << endl;
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}