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
    i64 n, m;
    cin >> n >> m;
    vvint a(n, vint(m));
    vvint b(n, vint(m));
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    /* 
        子矩阵转置
        guessing可得每个平行于副对角线元素集合保持不变
    */
    // i64 ok = 1;
    i64 k = n + m - 2;
    for (i64 i = 0; i <= k; i++) {
        multiset<i64> v1, v2;
        for (i64 j = 0; j < n; j++) {
            i64 p = i - j;
            if (p >= 0 && p < m) {
                v1.insert(a[j][p]);
                v2.insert(b[j][p]);
            }
        }
        if (v1 != v2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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