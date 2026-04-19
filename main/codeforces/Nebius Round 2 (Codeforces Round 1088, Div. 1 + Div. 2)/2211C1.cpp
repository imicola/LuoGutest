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
    set<i64> sb;
    i64 ok = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
        if (sb.count(b[i])) {
            ok = 1;
        }
        if (b[i] != -1) {
            sb.insert(b[i]);
        }
    }
    if (ok) {
        cout << "NO" << endl;
        return;
    }
    /* 
        题意大概是，给定两个数组与一个k，看对于每个位置的i与前k个数构成的区间块元素是否相同
        题目保证a是一个排列，但是b有-1的存在可以替换为任意数
        显然如果b中出现重复的数就会必然少一个其他的数
        我们是不是不用管b中的-1,保证b中出现的数都在a对应区间中就行了
    */
    // 分为两种情况，如果 k <= n/2 那么b中所有数都得与a对齐
    // 如果 k > n/2, 那么前 n-k个数都得与a对齐
    if (k <= n / 2) {
        for (i64 i = 0; i < n; i++) {
            if (b[i] != -1 && b[i] != a[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    else {
        for (i64 i = 0; i < n - k; i++) {
            if (b[i] != -1 && b[i] != a[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        set<i64> sa;
        for (i64 i = n - k; i < k; i++) {
            sa.insert(a[i]);
        }
        for (i64 i = n - k; i < k; i++) {
            if (b[i] != -1 && !sa.count(b[i])) {
                cout << "NO" << endl;
                return;
            }
        }
        for (i64 i = k; i < n; i++) {
            if (b[i] != -1 && b[i] != a[i]) {
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