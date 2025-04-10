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
    double x1, x2, x3;
    double y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    double mid1x = (x1 + x2) / 2, mid1y = (y1 + y2) / 2;
    double mid2x = (x3 + x2) / 2, mid2y = (y3 + y2) / 2;
    double mid3x = (x1 + x3) / 2, mid3y = (y1 + y3) / 2;
    if (x3 == mid1x && x3 == 0) {
        cout << "yes" << endl;
        return;
    }
    if (x2 == mid3x && x2 == 0) {
        cout << "yes" << endl;
        return;
    }
    if (x1 == mid2x && x1 == 0) {
        cout << "yes" << endl;
        return;
    }
    if (y1 == mid2y && y1 == 0) {
        cout << "yes" << endl;
        return;
    }
    if (y3 == mid1y && y3 == 0) {
        cout << "yes" << endl;
        return;
    }
    if (y2 == mid3y && y2 == 0) {
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
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