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
    i64 n, m, k;
    cin >> n >> m >> k;
    vvint A(n + 2, vint(m + 2, 0));
    vvint B(n + 2, vint(m + 2, 0));
    while (k--) {
        i64 x1, y1, x2, y2, a, b;
        cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
        A[x1][y1] += a;
        A[x2 + 1][y2 + 1] += a;
        A[x1][y2 + 1] -= a;
        A[x2 + 1][y1] -= a;
        B[x1][y1] += b;
        B[x2 + 1][y2 + 1] += b;
        B[x1][y2 + 1] -= b;
        B[x2 + 1][y1] -= b;
    }
    vvint pA(n + 1, vint(m + 1));
    vvint pB(n + 1, vint(m + 1));
    auto tran = [&](vvint &X, vvint &pX) -> void {
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = 1; j <= m; j++) {
                X[i][j] += X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1];
            }
        }
        pX = X;
    };
    tran(A, pA);
    tran(B, pB);
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            i64 k1 = i * i * pA[i][j];
            i64 k2 = j * j * pB[i][j];
            cout << k1 + k2 << " ";
        }
        cout << endl;
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