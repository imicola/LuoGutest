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
    int sum = 0;
    for (auto &&i : v) {
        cin >> i;
        sum += i;
    }
    int odd = 0, edd = 0;
    for (auto &&i : v) {
        if (i % 2 == 1) {
            edd++;
        }
        else {
            odd++;
        }
    }
    if (odd == 0 || edd == 0) {
        cout << ranges::max(v) << endl;
        return;
    }
    cout << sum - (edd - 1) << endl;
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