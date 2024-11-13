//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int xa, ya, xb, yb, xc, yc, xd, yd;
        cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        int ans = 0;
        if (max(xa, xb) < min(xc, xd) || max(xc, xd) < min(xa, xb)) ans++;
        if (max(ya, yb) < min(yc, yd) || max(yc, yd) < min(ya, yb)) ans++;
        cout << ans << endl;
    }
    return 0;
}