//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;

void solve() {
    i64 n, q;
    cin >> n >> q;
    vint a(n);
    for (i64 i = 0; i < n; ++i) cin >> a[i];

    i64 orall = 0;
    for (auto &x : a) orall |= x;
    i64 init = __builtin_popcountll(orall);

    vint costs;
    costs.reserve(32);
    for (int k = 0; k < 31; k++) {              
        if ((orall >> k) & 1) continue;
        i64 half = 1LL << k;
        i64 cycle = half << 1;
        i64 best = 4e18;               
        for (auto &x : a) {
            i64 pos = x & (cycle - 1);
            if (pos < half) {
                i64 diff = half - pos;
                if (diff < best) best = diff;
            }
        }
        if (best < 4e18) costs.push_back(best);
    }

    sort(all(costs));
    int m = (int)costs.size();
    vint pref(m + 1, 0);
    for (int i = 0; i < m; ++i) pref[i + 1] = pref[i] + costs[i];

    while (q--) {
        i64 b; cin >> b;
        int t = int(upper_bound(all(pref), b) - pref.begin()) - 1;
        if (t < 0) t = 0;
        cout << (init + t) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 T; 
    cin >> T;
    while (T--) solve();
    return 0;
}