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
    vint a(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    vint premax(n, 0);
    premax[0] = a[0];
    if (n <= 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        cout << (a[0] >= a[1] ? 1 : 0) << endl;
        return;
    }
    for (i64 i = 1; i < n; i++) {
        premax[i] = max(premax[i - 1], a[i]);
    }
    i64 cnt = 0;
    for (i64 i = 1; i + 1 < n; i += 2) {
        a[i] = premax[i];
        cnt += max(0ll, a[i - 1] - a[i] + 1);
        cnt += max(0ll, a[i + 1] - a[i] + 1);
        a[i - 1] = min(a[i] - 1, a[i - 1]);
        a[i + 1] = min(a[i] - 1, a[i + 1]);
    }
    cout << cnt << endl;
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