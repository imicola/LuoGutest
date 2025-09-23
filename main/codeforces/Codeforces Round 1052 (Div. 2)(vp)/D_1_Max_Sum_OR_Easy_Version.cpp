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

inline i64 ksm(i64 a, i64 b)
{
    if (b < 0) return 0;
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    i64 l, r;
    cin >> l >> r;
    vint a(r + 1, -1), b(r + 1);
    iota(all(b), 0);
    // 2^n - 1
    auto tp = [&](i64 x) { return 64 - __builtin_clzll(x); };
    // cout << tp(0) << endl;
    for (int i = r; i >= 0; i--) {
        if (a[i] != -1) continue;
        if (i == 0) {
            a[i] = 0;
            continue;
        }
        i64 k = tp(i);
        i64 k2 = ksm(2, k - 1); 
        i64 diff = i - k2;      
        a[i] = k2 - diff - 1;  
        a[k2 - diff - 1] = i;  
    }
    i64 sum = 0;
    for (i64 i = 0; i <= r; i++) {
        sum += b[i] | a[i];
    }
    cout << sum << endl;
    for (auto &&k : a) {
        cout << k << " ";
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