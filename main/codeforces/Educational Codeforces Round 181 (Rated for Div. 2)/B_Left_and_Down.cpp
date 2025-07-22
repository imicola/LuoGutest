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
    int a, b, k;
    cin >> a >> b >> k;
    // x,y -> 0,0
    if (k >= max(a, b)) {
        cout << 1 << endl;
        return;
    }
    if (a == 0 && b == 0) {
        cout << 0 << endl;
        return;
    }
    if (a == 0 || b == 0) {
        cout << 1 << endl;
        return;
    }
    int g = __gcd(a, b);
    a /= g, b /= g;
    if (k >= max(a, b)) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
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