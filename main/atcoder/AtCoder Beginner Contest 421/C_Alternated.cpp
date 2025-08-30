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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = "", s2 = "";
    for (size_t i = 0; i < 2 * n; i++) {
        if (i & 1) {
            s1 += 'A';
            s2 += 'B';
        }
        else {
            s1 += 'B';
            s2 += 'A';
        }
    }
    int cnt1 = 0;
    vint cab, cba;
    for (size_t i = 0; i < 2 * n; i++) {
        if (s[i] != s1[i] && s[i] == 'A') cab.emplace_back(i);
        if (s[i] != s1[i] && s[i] == 'B') cba.emplace_back(i);
    }
    for (size_t i = 0; i < cab.size(); i++) {
        cnt1 += abs(cab[i] - cba[i]);
    }
    int cnt2 = 0;
    vint c2ab, c2ba;
    for (size_t i = 0; i < 2 * n; i++) {
        if (s[i] != s2[i] && s[i] == 'A') c2ab.emplace_back(i);
        if (s[i] != s2[i] && s[i] == 'B') c2ba.emplace_back(i);
    }
    for (size_t i = 0; i < c2ab.size(); i++) {
        cnt2 += abs(c2ab[i] - c2ba[i]);
    }
    cout << min(cnt1, cnt2);
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