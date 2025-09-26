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
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    auto f = [&](char c) -> i64 {
        vint a;
        for (i64 i = 0; i < n; i++) {
            if (s[i] == c) a.push_back(i);
        }
        if (a.size() <= 1) return 0;
        vint q(a.size());
        for (i64 i = 0; i < a.size(); i++) {
            q[i] = a[i] - i;
        }
        i64 mid = q[a.size() / 2];
        i64 res = 0;
        for (i64 i = 0; i < a.size(); i++) {
            res += abs(q[i] - mid);
        }
        return res;
    };
    cout << min(f('a'), f('b')) << endl;
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