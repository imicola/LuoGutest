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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vint diff(n + 2, 0);
    // 构造1base差分数组，并将[l,r]区间+1
    for (size_t i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
    // 差分前缀和构造原数组
    vint v(n + 2,0);
    for (size_t i = 1; i <= n + 1; i++) {
        v[i] = v[i - 1] + diff[i];
    }
    // 计数，如果idx出现奇数次取T字符串字符，反之取S
    for (size_t i = 1; i <= n; i++) {
        if (v[i] & 1)
            cout << t[i - 1];
        else
            cout << s[i - 1];
    }
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