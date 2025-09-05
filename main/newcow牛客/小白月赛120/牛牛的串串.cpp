//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    map<char, i64> mp;
    for (size_t i = 0; i < n; i++) {
        char c;
        cin >> c;
        mp[c]++;
    }
    vint v;
    for (auto &&[a, b] : mp) {
        v.emplace_back(b);
    }
    ranges::sort(v);
    for (size_t i = 0; i + 1 < v.size(); i++) {
        if (v[i + 1] - v[i] != 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}