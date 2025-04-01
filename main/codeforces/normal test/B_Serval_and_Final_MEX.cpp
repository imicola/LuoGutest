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
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    auto ve = v | views::take(n - 2);
    // auto vi = ve | ranges::to<vector>();
    ranges::sort(ve);
    ranges::unique(ve);
    int minans = 0;
    for (auto &&i : ve) {
        if (i != minans) {
            break;
        }
        minans++;
    }
    if (minans != 0) {
        if (v[n - 1] * v[n - 2] != 0) {
            cout << 2 << endl;
            cout << 1 << " " << n - 2 << endl;
            cout << 1 << " " << 3 << endl;
        }
        else {
            cout << 3 << endl;
            cout << 1 << " " << n - 2 << endl;
            cout << 2 << " " << 3 << endl;
            cout << 1 << " " << 2 << endl;
        }
    }
    else {
        if (v[n - 1] * v[n - 2] != 0) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }
        else {
            cout << 2 << endl;
            cout << n - 1 << " " << n << endl;
            cout << 1 << " " << n - 1 << endl;
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