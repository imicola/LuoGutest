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
    vint a(n);
    i64 Max = 0, idx = 0;
    bool all0 = 1;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        if (Max <= a[i]) Max = a[i], idx = i;
        if (a[i] != 0 && i != 0) all0 = 0;
    }
    if (n == 1) {
        cout << n << endl;
        cout << a[0] << endl;
        return;
    }
    if (all0) {
        cout << n << endl;
        for (auto &&i : a) {
            cout << i << " ";
        }
        return;
    }
    if (idx != 0) {
        cout << n - 1 << endl;
        a[0] += Max;
        for (i64 i = 0; i < n; i++) {
            if (i == idx) continue;
            cout << a[i] << " ";
        }
        return;
    }
    i64 idx2 = max_element(a.begin() + 1, a.end()) - a.begin();
    cout << n - 1 << endl;
    a[0] += a[idx2];
    for (i64 i = 0; i < n; i++) {
        if (i == idx2) continue;
        cout << a[i] << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}