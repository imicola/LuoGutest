//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl '\n'
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
    auto ask = [&](i64 i, i64 x) -> void { cout << "? " << i << " " << x << endl; };
    i64 isodd = 0;
    vint v(n);
    i64 cur = 0;
    for (i64 i = 1; i <= n - 1; i++) {
        ask(1, i);
        i64 res = 0;
        cin >> res;
        v[i] = res;
        isodd += res;
    }
    if (isodd & 1) {
        cur = 0;
    }
    else {
        cur = 1;
    }
    vint vn;
    for (i64 i = 1; i < n; i++) {
        if ((v[i] & 1) == cur) {
            vn.emplace_back(i);
        }
    }
    i64 top = 64 - __builtin_clzll(n);
    top -= 1;
    
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