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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = 1;
    int n1 = (a > (n + 1) / 2 ? n - a + 1 : a), m1 = (b > (m + 1) / 2 ? m - b + 1 : b);
    int h1 = 0, h2 = 0;
    auto f = [](int x, int y) {
        int height = 0;
        int tempX = x, tempY = y;
        while (tempX > 1) {
            tempX = (tempX + 1) / 2;
            height++;
        }
        while (tempY > 1) {
            tempY = (tempY + 1) / 2;
            height++;
        }
        return height;
    };
    h1 = f(n1, m);
    h2 = f(n, m1);
    cout << min(h1, h2) + 1 << endl;
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