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
    int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
    sx1 *= 2, sy1 *= 2, sx2 *= 2, sy2 *= 2, tx1 *= 2, ty1 *= 2, tx2 *= 2, ty2 *= 2;
    int smidx1 = (sx1 + sx2);
    int smidy1 = (sy1 + sy2);
    int tmidx1 = (tx1 + tx2);
    int tmidy1 = (ty1 + ty2);
    if ((smidx1 + smidy1) % 2 != (tmidx1 + tmidy1) % 2) {
        cout << -1 << endl;
        return;
    }
    int k1 = abs(tmidx1 - smidx1);
    int k2 = abs(tmidy1 - smidy1);
    int m = max(k1, k2);
    if(m % 2 != k1 % 2){
        m++;
    }
    cout << m / 2 << endl;
}
/*
    a *= 2,b -> c,d
    
*/
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}