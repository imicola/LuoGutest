//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    vint ans;
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans.emplace_back(i + 1);
        }
    }
    if (ans.size() == 0) {
        cout << 0 << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
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