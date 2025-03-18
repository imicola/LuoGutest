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

void solve()
{
    int a, b, n, m, h;
    cin >> a >> b >> n >> m >> h;
    int l = n, r = n + m, ans = 0;
    while (l < r) {
        int w = (l + r + 1) / 2;
        int rest = n + m - w;
        auto check = [&]() -> bool {
            int ans1 = 0;
            int w1 = w;
            ans1 += (n / b) * (h - a);
            w1 -= b * (n / b);
            ans1 += (w1 / b) * (h - b);
            return ans1 >= rest;
        };
        if (check()) {
            r = w;
            // ans = w;
        }
        else {
            l = w;
        }
    }
    cout << l << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}