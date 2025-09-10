// #pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
// #define size_t int
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
    i64 cnt0 = 0, cnt1 = 0;
    for (auto &&i : s) {
        if (i == '0')
            cnt0++;
        else
            cnt1++;
    }
    i64 ans = 0;
    for (size_t i = 0; i < cnt0; i++) {
        if (s[i] == '1') ans++;
    }
    i64 ans2 = 0;
    for (size_t i = cnt0; i < n; i++) {
        if (s[i] == '0') ans2++;
    }
    cout << min(ans2, ans) << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}