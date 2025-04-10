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

int indextomun(int n, int x, int y)
{
    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 2 && y == 2) return 2;
        if (x == 2 && y == 1) return 3;
        if (x == 1 && y == 2) return 4;
    }
    else {
        int h = (1LL << (n - 1));
        int h2 = (1LL << (2 * (n - 1)));
        if (x <= h && y <= h) return indextomun(n - 1, x, y);
        if (x <= h && y > h) return 3 * h2 + indextomun(n - 1, x, y - h);
        if (x > h && y > h) return h2 + indextomun(n - 1, x - h, y - h);
        if (x > h && y <= h) return 2 * h2 + indextomun(n - 1, x - h, y);
    }
}

pii dtoindedx(int n, int d)
{
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 4) return {1, 2};
        if (d == 3) return {2, 1};
    }
    else {
        int h = (1LL << (n - 1));
        int h2 = (1LL << (2 * (n - 1)));
        int q = (d - 1) / h2;
        int r = d - q * h2;
        auto [x, y] = dtoindedx(n - 1, r);
        if (q == 0) return {x, y};
        if (q == 1) return {x + h, y + h};
        if (q == 2) return {x + h, y};
        if (q == 3) return {x, y + h};
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    while (q--) {
        char ch1;
        cin >> ch1 >> ch1;
        // d -> x,y;
        if (ch1 == '-') {
            int d;
            cin >> d;
            auto [x, y] = dtoindedx(n, d);
            cout << x << " " << y << endl;
        }
        //x,y -> d
        else {
            int x, y;
            cin >> x >> y;
            cout << indextomun(n, x, y) << endl;
        }
    }
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