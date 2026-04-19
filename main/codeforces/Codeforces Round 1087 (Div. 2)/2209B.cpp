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
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

struct Fenwick
{
    i64 n;
    vint bit;
    Fenwick(i64 n): n(n), bit(n + 1, 0) { }
    void add(i64 i, i64 v = 1)
    {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    i64 sum(i64 i)
    {
        i64 r = 0;
        for (; i > 0; i -= i & -i) r += bit[i];
        return r;
    }
    i64 sum(i64 l, i64 r)
    {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    i64 n;
    cin >> n;
    vint v(n + 1);
    map<i64, vint> mp;
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]].emplace_back(i);
    }
    i64 idx = 1;
    vint dis(n + 1);
    for (auto &&[i, j] : mp) {
        for (auto &&k : j) {
            dis[k] = idx;
        }
        idx++;
    }
    vint sufmax(n + 1);
    vint sufmin(n + 1);
    Fenwick fw(n + 1);
    for (i64 i = n; i >= 1; i--) {
        sufmin[i] = fw.sum(dis[i] - 1);
        sufmax[i] = fw.sum(dis[i] + 1, n);
        fw.add(dis[i]);
    }
    for (i64 i = 1; i <= n; i++) {
        cout << max(sufmax[i], sufmin[i]) << " ";
    }
    cout << endl;
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