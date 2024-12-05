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
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vint a(10100), b(10100), g(10100), k(10100);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (size_t i = 0; i < n; i++) {
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i]) {
            ans = i + 1;
        }
    }
    cout << ans;
}