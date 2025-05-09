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
    int n, k;
    cin >> n >> k;
    vint v(n);
    map<int, int> mp;
    int sum = 0;
    for (auto &&i : v) {
        cin >> i;
        mp[i]++;
        sum += i;
    }
    auto [minn, maxx] = ranges::minmax(v);
    if (maxx - minn > k + 1) {
        cout << "Jerry" << endl;
        return;
    }
    if (maxx - minn <= k) {
        cout << (sum % 2 == 0 ? "Jerry" : "Tom") << endl;
        return;
    }
    if (maxx - minn == k + 1) {
        if (mp[maxx] != 1) {
            cout << "Jerry" << endl;
        }
        else {
            cout << (sum % 2 == 0 ? "Jerry" : "Tom") << endl;
            return;
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