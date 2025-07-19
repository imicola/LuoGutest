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
    vint p(n), s(n);
    for (auto &&i : p) {
        cin >> i;
    }
    for (auto &&i : s) {
        cin >> i;
    }
    if (p.back() != s.front()) {
        cout << "NO" << endl;
        return;
    }
    for (size_t i = 1; i < n; i++) {
        if (p[i - 1] % p[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    for (size_t i = 0; i + 1 < n; i++) {
        if (s[i + 1] % s[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    if (s[0] != gcd(p[0], s[1]) || p[n - 1] != gcd(p[n - 2], s[n - 1])) {
        cout << "NO" << endl;
        return;
    }
    for (size_t i = 0; i + 1 < n; i++) {
        if (gcd(p[i], s[i + 1]) != p[n - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    for (size_t i = 1; i + 1 < n; i++) {
        int g = gcd(p[i], s[i]);
        if (gcd(p[i - 1] / p[i], s[i] / g) != 1 || gcd(p[i] / g, s[i + 1] / s[i]) != 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}