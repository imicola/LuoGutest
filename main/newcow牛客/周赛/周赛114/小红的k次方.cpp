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
    vint v(n);
    i64 mul = 1;
    i64 ans = 0;
    map<i64, i64> mp;
    // 考虑整数完全分解定理
    i64 cnt2 = 0;
    i64 cnt3 = 0;
    i64 cnt5 = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        while (v[i] % 2 == 0) {
            v[i] /= 2;
            cnt2++;
        }
        while (v[i] % 3 == 0) {
            v[i] /= 3;
            cnt3++;
        }
        while (v[i] % 5 == 0) {
            v[i] /= 5;
            cnt5++;
        }
    }

    cout << min({cnt2, cnt3, cnt5}) << endl;
}
/* 

30 15 3 5 6 2

*/
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