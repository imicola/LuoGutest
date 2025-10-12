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
    i64 n, m, k;
    cin >> n >> m >> k;
    i64 sty, stx, edy, edx;
    cin >> sty >> stx >> edy >> edx;
    unordered_map<i64, vint> X;
    unordered_map<i64, vint> Y;
    unordered_map<i64, unordered_map<i64, i64>> mp;
    unordered_map<i64, unordered_map<i64, i64>> edmp;
    X.reserve(2e5);
    Y.reserve(2e5);
    mp.reserve(2e5);
    edmp.reserve(2e5);
    for (i64 i = 0; i < k; i++) {
        i64 y, x;
        cin >> y >> x;
        mp[y][x] = 1;
        X[y].emplace_back(x);
        Y[x].emplace_back(y);
    }

    auto has_block = [&](i64 y, i64 x) -> bool {
        auto it = mp.find(y);
        if (it == mp.end()) return false;
        return it->second.find(x) != it->second.end();
    };
    auto has_ed = [&](i64 y, i64 x) -> bool {
        auto it = edmp.find(y);
        if (it == edmp.end()) return false;
        return it->second.find(x) != it->second.end();
    };

    // 以 ed 为中心四向扩展：遇到当前格是障碍则停止
    for (i64 i = edx; i <= m; i++) {
        if (has_block(edy, i)) break;
        edmp[edy][i] = 1;
    }
    for (i64 i = edx; i >= 1; i--) {
        if (has_block(edy, i)) break;
        edmp[edy][i] = 1;
    }
    for (i64 i = edy; i <= n; i++) {
        if (has_block(i, edx)) break;
        edmp[i][edx] = 1;
    }
    for (i64 i = edy; i >= 1; i--) {
        if (has_block(i, edx)) break;
        edmp[i][edx] = 1;
    }
    for (i64 i = stx; i <= m; i++) {
        if (has_block(sty, i)) break;
        if (has_ed(sty, i)) {
            cout << "YES" << endl;
            return;
        }
        if (has_ed(edy, i)) {
            bool ok = true;
            i64 big = max(sty, edy);
            i64 sma = min(sty, edy);
            auto itY = Y.find(i);
            if (itY != Y.end()) {
                for (auto &&yy : itY->second) {
                    if (yy < big && yy > sma) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    for (i64 i = stx; i >= 1; i--) {
        if (has_block(sty, i)) break;
        if (has_ed(sty, i)) {
            cout << "YES" << endl;
            return;
        }
        if (has_ed(edy, i)) {
            bool ok = true;
            i64 big = max(sty, edy);
            i64 sma = min(sty, edy);
            auto itY = Y.find(i);
            if (itY != Y.end()) {
                for (auto &&yy : itY->second) {
                    if (yy < big && yy > sma) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    for (i64 i = sty; i <= n; i++) {
        if (has_block(i, stx)) break;
        if (has_ed(i, stx)) {
            cout << "YES" << endl;
            return;
        }
        if (has_ed(i, edx)) {
            bool ok = true;
            i64 big = max(stx, edx);
            i64 sma = min(stx, edx);
            auto itX = X.find(i);
            if (itX != X.end()) {
                for (auto &&xx : itX->second) {
                    if (xx < big && xx > sma) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    for (i64 i = sty; i >= 1; i--) {
        if (has_block(i, stx)) break;
        if (has_ed(i, stx)) {
            cout << "YES" << endl;
            return;
        }
        if (has_ed(i, edx)) {
            bool ok = true;
            i64 big = max(stx, edx);
            i64 sma = min(stx, edx);
            auto itX = X.find(i);
            if (itX != X.end()) {
                for (auto &&xx : itX->second) {
                    if (xx < big && xx > sma) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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