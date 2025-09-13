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
    i64 n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    // 要么就是A少或者B少不足以分完
    // 要么就是将所有的平均分为3份
    i64 ans = min(min(n1, n3), (n1 + n2 + n3) / 3);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}