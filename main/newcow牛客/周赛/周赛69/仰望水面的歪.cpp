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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, h;
    cin >> n >> h;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        int z2 = h + (h - z);
        int gcdx = __gcd(x, __gcd(y,z2));
        // int gcdx = 1;
        cout << x / gcdx << " " << y / gcdx<<" "<< z2 / gcdx << endl;
    }

    return 0;
}