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

/* 
    我们需要最大化最短抵达时间
    那就是尽可能在diff小的区间后放
    注意处理最后一个区间,我们可以放到边界位置
    我们可以先确定最后最短长度,然后开始放就行了?
    那我们如何进行确定最大?
    尝试二分
*/

void solve()
{
    i64 n, k, x;
    cin >> n >> k >> x;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    sort(all(v));
    i64 L = 0, R = x + 1;
    i64 d = 0;
    while (L + 1 < R) {
        i64 mid = (L + R) >> 1;
        auto check = [&](i64 mid) -> bool {
            // 0 ~ a[0] - mid
            i64 res = 0;
            i64 l1 = 0, r1 = v[0] - mid;
            if (r1 >= 0 && r1 >= l1) res += min(r1, x) - l1 + 1;
            for (i64 i = 0; i + 1 < n; i++) {
                i64 l2 = v[i] + mid;
                i64 r2 = v[i + 1] - mid;
                if (r2 < l2) continue;
                l2 = max(l2, 0ll);
                r2 = min(r2, x);
                if (r2 >= l2) res += (r2 - l2 + 1);
            }
            i64 l3 = v[n - 1] + mid;
            i64 r3 = x;
            if (r3 >= l3) res += (r3 - max(l3, 0ll) + 1);
            return res >= k;
        };
        if (check(mid)) {
            L = mid;
            d = L;
        }
        else {
            R = mid;
        }
    }
    vint ans;
    ans.reserve(k);
    auto make = [&](i64 l, i64 r) {
        if (r < l) return;
        l = max(l, 0ll);
        r = min(r, x);
        if (!ans.empty() && l <= ans.back()) l = ans.back() + 1;
        for (i64 i = l; i <= r && ans.size() < k; ++i) ans.emplace_back(i);
    };
    make(0, v[0] - d);
    for (i64 i = 0; i + 1 < n && ans.size() < k; i++) {
        make(v[i] + d, v[i + 1] - d);
    }
    make(v[n - 1] + d, x);
    for (auto &&i : ans) {
        cout << i << " ";
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