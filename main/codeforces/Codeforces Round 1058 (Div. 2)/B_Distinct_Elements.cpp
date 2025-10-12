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
    vint b(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vint a(n + 1);
    i64 cnt = 0;
    i64 now = 0;
    for (i64 i = 1; i <= n; i++) {
        i64 idx = b[i] - cnt;
        cnt = b[i];
        i64 pre = i - idx;
        if (pre == 0) {
            now++;
            a[i] = now;
        }
        else {
            a[i] = a[pre];
        }
    }
    for (i64 i = 1; i <= n; i++) {
        cout << a[i] << " ";
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