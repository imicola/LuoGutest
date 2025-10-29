//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n;
    string s, t;
    cin >> n >> s >> t;
    map<char, i64> mp;
    for (auto &&i : s) {
        mp[i]++;
    }
    i64 ok = 1;
    for (auto &&i : t) {
        if (mp[i] == 0)
            ok = 0;
        else {
            mp[i]--;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}