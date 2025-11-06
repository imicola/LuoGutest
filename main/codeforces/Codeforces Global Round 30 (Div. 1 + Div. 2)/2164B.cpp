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
    i64 n;
    cin >> n;
    vint v(n);
    // set<i64> evens;
    vint odds, evens;
    odds.reserve(n), evens.reserve(n);
    // i64 idx = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] & 1) {
            odds.emplace_back(v[i]);
        }
        else {
            evens.emplace_back(v[i]);
        }
    }
    // 偶数任取
    if (evens.size() >= 2) {
        cout << evens[0] << " " << evens[1] << endl;
        return;
    }
    // bool ok = 0;
    // 奇数
    i64 len = odds.size();
    for (i64 i = 0; i < len - 1; i++) {
        i64 k1 = odds[i];
        i64 k2 = odds[i + 1];
        if (k2 < k1 * 2) {
            cout << k1 << " " << k2 << endl;
            return;
        }
    }
    // 整除
    set<i64> st;
    for (auto &&i : v) {
        st.insert(i);
    }
    for (i64 j = 0; j < n; j++) {
        i64 y = v[j];
        for (i64 d = 1; d * d <= y; d++) {
            if (y % d == 0) {
                i64 d1 = d, d2 = y / d;
                if (d1 < y && st.count(d1)) {
                    cout << d1 << " " << y << endl;
                    return;
                }
                if (d2 < y && d2 != d1 && st.count(d2)) {
                    cout << d2 << " " << y << endl;
                    return;
                }
            }
        }
    }
    // check
    i64 Lim = 2000;
    bool ok = 0;
    if (n <= Lim) {
        for (i64 i = 0; i < n && !ok; i++) {
            for (i64 j = i + 1; j < n; j++) {
                i64 r = v[j] % v[i];
                if ((r & 1) == 0) {
                    cout << v[i] << " " << v[j] << endl;
                    return;
                }
            }
        }
    }
    else {
        const i64 x = 500;
        for (i64 i = 0; i < n && !ok; ++i) {
            i64 up = min(n, i + 1 + x);
            for (i64 j = i + 1; j < up; ++j) {
                i64 r = v[j] % v[i];
                if ((r & 1) == 0) {
                    cout << v[i] << " " << v[j] << endl;
                    return;
                }
            }
        }
    }
    cout << "-1" << endl;
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