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
    vint v(n + 1);
    for (i64 i = 1; i <= n; i++) {
        char c;
        cin >> c;
        v[i] = (c - '0');
    }
    vint pre(n + 1);
    // max(a,b) = (a + b - abs(a - b))/2
    /* 
        ΣP(L,R,max(cnta,cntb)) = tot + Σ(cnt1 - cnt0)
        a + b 为子串的长度，我们可以预统计这个子串长度
        abs(a - b)我们可以拆位贡献
        我们记录一个前缀和pre = cnt1 - cnt0
        即pre(R,a) - pre(R,l - 1)
    */
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (v[i] == 1 ? 1 : -1);
    }
    i64 tot = 0;
    for (i64 i = 1; i <= n; i++) {
        tot += i * (n - i + 1);
    }
    i64 tot2 = 0;
    sort(all(pre));
    for (i64 i = 0; i <= n; i++) {
        tot2 += (pre[i] * i) - (pre[i] * (n - i));
    }
    cout << (tot2 + tot) / 2 << endl;
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