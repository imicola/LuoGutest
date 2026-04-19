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
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n;
    cin >> n;
    vint p1(n), p2(n);
    for (auto &&i : p1) {
        cin >> i;
    }
    for (auto &&i : p2) {
        cin >> i;
    }
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        mp[p1[i]] = i;
    }
    vint res(n);
    for (i64 i = 0; i < n; i++) {
        res[i] = mp[p2[i]];
    }
    auto Lis = [](vint v) -> i64 {
        vint res;
        for (auto &&i : v) {
            auto it = lower_bound(all(res), i);
            if (it == res.end())
                res.emplace_back(i);
            else
                *it = i;
        }
        return res.size();
    };
    cout << Lis(res) << endl;
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