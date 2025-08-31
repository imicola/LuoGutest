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
    int x, y;
    cin >> x >> y;
    auto f = [](int a) -> int {
        string s1 = to_string(a);
        ranges::reverse(s1);
        int t = stoll(s1);
        return t;
    };
    vint res(10);
    res[0] = x;
    res[1] = y;
    for (size_t i = 2; i < 10; i++) {
        res[i] = f(res[i - 1] + res[i - 2]);
        // cout << res[i] << endl;
    }
    cout << res[9] << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}