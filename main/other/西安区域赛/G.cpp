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
    vint v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
    }
    vint v2 = v;
    sort(all(v));
    sort(all(v2), [](i64 a, i64 b) { return a > b; });
    i64 s1 = 0;
    for (auto &&i : v) {
        if (s1 >= i) {
            s1++;
        }
        else {
            s1--;
        }
    }
    i64 s2 = 0;
    for (auto &&i : v2) {
        if (s2 >= i) {
            s2++;
        }
        else {
            s2--;
        }
    }

    cout << s1 << " " << s2 << endl;
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