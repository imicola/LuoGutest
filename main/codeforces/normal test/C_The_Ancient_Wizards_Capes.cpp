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
    vint v(n);
    bool ok = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        if (i != 0 && abs(v[i] - v[i - 1]) >= 2) ok = 1;
    }
    if (ok) {
        cout << 0 << endl;
        return;
    }
    /*
    我们关注从 i 到 i + 1的过程
    不难发现从 1~i-1 和 i + 2的情况是一致的
    所以我们可以只考虑当前两个并且往后递推 
    i j
    < > j = i
    < < j = i+1
    > > j = i-1
    > < j = i
    对于初始情况，不难想到初始只有朝向左和朝向右两种情况
    */
    vint a1(n, 0), a2 = a1;
    a1[0] = 0;
    a2[0] = 1;
    for (i64 i = 1; i < n; i++) {
        if (v[i] - v[i - 1] != 0) {
            a1[i] = a1[i - 1];
            a2[i] = a2[i - 1];
        }
        else {
            a1[i] = 1 - a1[i - 1];
            a2[i] = 1 - a2[i - 1];
        }
    }
    auto check = [&](vint a) -> bool {
        i64 cnt = 1;
        for (i64 i = 1; i < n; i++) {
            if (a[i] == 1) cnt++;
        }
        i64 res = 0;
        if (cnt == v[0]) {
            res = 1;
            for (i64 i = 0; i + 1 < n; i++) {
                if (a[i] == 1 && a[i + 1] == 1) {
                    cnt--;
                }
                if (a[i] == 0 && a[i + 1] == 0) {
                    cnt++;
                }
                if (v[i + 1] != cnt) {
                    res = 0;
                }
            }
        }
        return res;
    };
    i64 ans = 0;
    if (check(a1)) ans++;
    if (check(a2)) ans++;
    cout << ans << endl;
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