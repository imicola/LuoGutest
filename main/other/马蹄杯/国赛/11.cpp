#pragma GCC optimize(2)
#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

void solve()
{
    const int MOD = 998244353;
    map<string, long long> mp;
    int n;
    cin >> n;
    string s;
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> s;
        string p = "";
        for (size_t k = 0; k < s.size(); k++) {
            p += s[k];
            mp[p]++;
        }
    }
    for (auto &&[a, b] : mp) {
        ans += (b * b) % MOD;
    }
    cout << ans % MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}