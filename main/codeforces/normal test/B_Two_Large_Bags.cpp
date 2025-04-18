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
    for (auto &&i : v) {
        cin >> i;
        mp[i]++;
    }
    // vpii vp(all(mp));
    auto [minn, maxx] = ranges::minmax(v);
    int ck = 0;
    for (int i = maxx; i >= minn; i--) {
        // cout << ck << " ck i " << i << endl;
        if (mp[i] - ck >= 0)
            mp[i] -= ck;
        else {
            ck -= mp[i];
            int need = 3 + (ck - 1);
            ck = need;
            continue;
        }
        ck = 0;
        if (mp[i] % 2 == 0)
            continue;
        else
            ck += 3;
    }
    cout << (ck > 0 ? "no" : "yes") << endl;
}
// nx -> x+1 要 3 个 x
// nx -> 2(x + 1) 要 4 x
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