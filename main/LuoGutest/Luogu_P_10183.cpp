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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    vector<LL> a(t);
    for (size_t i = 0; i < t; i++) {
        cin >> a[i];
        if (a[i] & 1 == 1) {
            cout << -1;
            return 0;
        }
    }
    LL g = a[0];
    for (size_t i = 1; i < t; i++) {
        g = __gcd(g, a[i]);
    }
    if ((g & 1) == 0)
        cout << g / 2;
    else
        cout << -1;
    return 0;
}