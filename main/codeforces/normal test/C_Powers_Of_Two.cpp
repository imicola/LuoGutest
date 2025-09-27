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
    i64 n, k;
    cin >> n >> k;
    i64 p = __builtin_popcountll(n);
    if (k > n || k < p) {
        cout << "NO" << endl;
        return;
    }
    vint cnt(64, 0);
    for (i64 i = 0; i < 63; i++) {
        if ((n >> i) & 1) cnt[i]++;
    }
    i64 cur = p;
    while (cur < k) {
        i64 i = 62;
        for (; i >= 0; i--) {
            if (cnt[i] > 0) break;
        }
        cnt[i]--;
        cnt[i - 1] += 2;
        cur++;
    }
    vint ans;
    for (i64 i = 0; i < 63; i++) {
        while (cnt[i] > 0) {
            ans.emplace_back(1ll << i);
            cnt[i]--;
        }
    }
    cout << "YES" << endl;
    for (auto &&i : ans) {
        cout << i << " ";
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