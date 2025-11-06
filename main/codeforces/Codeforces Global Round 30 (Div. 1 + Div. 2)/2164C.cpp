//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint a(n), b(m), c(m);
    for (auto &&i : a) cin >> i;
    for (auto &&i : b) cin >> i;
    /* 
        击杀ci > 0 的怪物可以是净赚的
        所以我们的策略是优先击杀ci > 0 的
        将ci = 0 的留到最后杀,因为杀一个少一把剑
        剩下的都是可行的,我们选择a中最大的一个元素去挑战所有可以挑战的然后更新
        如果变大,则继续去剩余的更新
        不会超过O(m)

        我们应该尽可能升级多把剑,我们用一个mulitset维护?
        每次二分找最符合的剑并且升级?
    */
    vint c0;
    c0.reserve(m);
    vpii vp;
    for (i64 i = 0; i < m; i++) {
        cin >> c[i];
        if (c[i] == 0)
            c0.emplace_back(b[i]);
        else {
            vp.emplace_back(b[i], c[i]);
        }
    }
    sort(all(vp));
    multiset<i64> mst(all(a));
    i64 ans = 0;
    for (auto &&[bx, cx] : vp) {
        auto it = mst.lower_bound(bx);
        if (it != mst.end()) {
            i64 x = *it;
            mst.erase(it);
            mst.insert(max(x, cx));
            ans++;
        }
    }
    // 比较0的
    sort(all(c0));
    i64 idxb = 0;
    for (auto &&i : mst) {
        if (idxb == c0.size()) break;
        if (i >= c0[idxb]) {
            ans++;
            idxb++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}