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
    map<int, int> mp;
    int minn = 1e18;
    for (auto &&i : v) {
        cin >> i;
        mp[i]++;
        minn = min(minn, i);
    }
    int p = mp[minn];
    if (p > 1) {
        cout << "Yes" << endl;
        return;
    }
    int cnt = 0;
    int ans = 0, gcds = 0;
    for (auto &&[a, b] : mp) {
        if (a % minn == 0 && a != minn) {
            if (gcds == 0) {
                gcds = a / minn;
                continue;
            }
            gcds = gcd(a / minn, gcds);
        }
    }
    cout << (gcds == 1 ? "Yes" : "No") << endl;
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