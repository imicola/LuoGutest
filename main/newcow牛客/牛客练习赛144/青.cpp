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
    i64 n, m;
    cin >> n >> m;
    i64 L = m + n;
    vint a(n);
    unordered_set<i64> st;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    ranges::sort(a);
    // 只要diff相差大于2就一定能构造,有两个diff = 2也可以
    vint diff(n);
    for (i64 i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
    i64 ok = 0, idx1 = 0, ok1 = 0, ok2 = 0;
    if (a[0] != 1) ok1 = 1;
    if (a[n - 1] != L) ok2 = 1;

    for (i64 i = 0; i < n; i++) {
        if (diff[i] > 2) {
            cout << a[i] << " " << a[i + 1] << " " << a[i] + 1 << " " << a[i + 1] - 1 << endl;
            return;
        }
        if (diff[i] == 2) {
            ok++;
            idx1 = i;
            if (ok == 2) {
                cout << a[idx1] << " " << a[i + 1] << " " << a[idx1] + 1 << " " << a[i + 1] - 1 << endl;
                return;
            }
        }
        if (ok2 && ok && idx1 + 1 != n - 1) {
            cout << a[idx1] + 1 << " " << a[idx1 + 1] << " " << a[n - 1] << " " << a[n - 1] + 1 << endl;
            return;
        }
        if (ok && ok1) {
            cout << a[0] - 1 << " " << a[0] << " " << a[idx1] << " " << a[idx1] + 1 << endl;
            return;
        }
        if (ok1 && ok2) {
            cout << a[0] - 1 << " " << a[0] << " " << a[n - 1] << " " << a[n - 1] + 1 << endl;
            return;
        }
        // cout << idx1 << endl;
    }
    cout << -1 << endl;
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