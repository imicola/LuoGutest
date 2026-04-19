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

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint a(n), b(n);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
    }
    // 现在a是任意的了
    // 考虑滑动窗口，从 [l,r] 到 [l + 1,r + 1] 我们会丢掉a[l] 加入a[r + 1]
    // 现在有两种情况，一种是b[l] = a[l] && b[r + 1] = a[r + 1]
    // 还有就是b[l] = a[r + 1] && b[r + 1] = a[l]
    // 考虑每个r = {0,1,2,3 ..} 对 k 取模有 链L_r = {b_r,b_r+k,b_r+2k,...}
    // 如果L_r中对应的a有非重复的数，那这个b就必须与a对齐
    // 如果L_r中对应的a都是同一个数: 那么b也必须是同一个数，则如果有不同的数，非法；
    // 如果仅有一个非-1，则这个链中都是这个数
    // 如果全是-1，则这个数待定
    vint visb(k, -1);
    vec<bool> ok(k, 0);
    for (i64 r = 0; r < k; r++) {
        i64 repeat = 1;
        i64 ai = a[r];
        i64 varb = -1;
        for (i64 i = r; i < n; i += k) {
            if (a[i] != ai) {
                repeat = 0;
            }
            if (b[i] != -1) {
                if (varb == -1) {
                    varb = b[i];
                }
                else if (repeat && varb != b[i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
        if (!repeat) {
            for (i64 i = r; i < n; i += k) {
                if (b[i] != -1 && b[i] != a[i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            visb[r] = a[r];
        }
        else {
            if (varb != -1) {
                visb[r] = varb;
            }
            else {
                ok[r] = 1;
            }
        }
    }
    map<i64, i64> cnt;
    for (i64 i = 0; i < k; i++) {
        cnt[a[i]]++;
    }
    for (i64 i = 0; i < k; i++) {
        if (!ok[i]) {
            if (cnt[visb[i]] > 0) {
                cnt[visb[i]]--;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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