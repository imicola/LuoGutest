//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
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
    i64 cnta = 0, cntb = 0;
    vint v(n);
    i64 idx = 0;
    i64 diff = 0;
    for (auto &&i : s) {
        if (i == 'a') cnta++, v[idx] = 1;
        if (i == 'b') cntb++, v[idx] = -1;
        idx++;
    }
    diff = cnta - cntb;
    if (diff == 0) {
        cout << 0 << endl;
        return;
    }
    vint pre(n + 1);
    pre[0] = v[0];
    for (i64 i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    vint first0(2 * n + 1, -1);
    first0[n] = 0;
    i64 ans = n + 1;
    for (i64 i = 1; i <= n; i++) {
        i64 need = pre[i - 1] - diff;
        i64 idx = need + n;
        if (idx >= 0 && idx <= 2 * n && first0[idx] != -1) {
            ans = min(ans, i - first0[idx]);
        }
        first0[pre[i - 1] + n] = i;
    }
    cout << (ans >= n ? -1 : ans) << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}