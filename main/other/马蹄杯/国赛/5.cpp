#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v, begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<string> vstr(n);
    int maxsz = INT_MIN;
    for (auto &&i : vstr) {
        cin >> i;
        maxsz = max((int)i.size(), maxsz);
    }
    unordered_map<string, int> path;
    for (size_t i = 1; i <= maxsz; i++) {
        for (auto &&s : vstr) {
            if (i > s.size()) continue;
            string pre = s.substr(0, i);
            // path[pre]++;
            string x = "";
            for (int p = 0; p < i; p++) {
                x += pre[p];
                path[x]++;
            }
        }
    }
    int ans = 0;
    for (auto &&[a, b] : path) {
        // for (auto &&i : vstr) {
        //     if (a.size() > i.size()) continue;
        //     string pre = i.substr(0, a.size());
        //     if (pre == a)
        // }
        cout << a << " " << b << endl;
        ans = (ans + b) % MOD;
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