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

/* 
    变化过程:
    我们认为sort后出现第一个出现"断点"的地方,即mp[x] = 0的地方,当 i > x时候所有i变为x
    当i < x时候,我们注意mp[i] >= 2的点,其也会等于x,紧接着在下一次变化中这个点将变成一个新的"断点"
    有一种特殊情况便是类似mp[i] >= 2 且其就是MEX,此时变化会进入交替状态,即i + 1 与 i之间的变化
    所以我们只需要最多两次变化就能确定其变化规律
    我们需要找到第一个 "断点" 以及第一个 mp[i] >= 2的点
    请直接看solve3
*/

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint a(n);
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    auto &&[Min, Max] = ranges::minmax(a);
    if (Min != 0) {
        cout << (k & 1 ? 0 : n) << endl;
        return;
    }

    // idx1 : 第一个mp[i] > 2的点  idx2 : 第一个断点
    i64 idx1 = -1, idx2 = -1;
    for (i64 i = 0; i <= n + 1; i++) {
        // 第一个mp[i] > 1 的点
        if (mp[i] > 1 && idx1 == -1) idx1 = i;
        // 第一个断点
        if (mp[i] == 0 && idx2 == -1) idx2 = i;
        if (idx1 != -1 && idx2 != -1) break;
    }
    // cout << idx1 << endl;
    // 第一次变化
    i64 ans = 0;
    // idx2,idx1 后有几个元素
    for (auto &&[i, val] : mp) {
        if ((i < idx2 && val > 1) || (i > idx2)) {
            ans += idx2 * val;
            mp[idx2] += val;
            val = 0;
        }
    }
    if (k == 1) {
        if (idx2 > Max && idx1 == -1) {
            cout << (n - 1) * n / 2 << endl;
            return;
        }
        cout << ans << endl;
        return;
    }
    // 手动模拟第二次第三次内容
    i64 ans2 = 0, ans3 = 0;
    i64 mex = 0;
    while (mex <= n && mp[mex] > 0) mex++;
    for (i64 i = 0; i <= n; i++) {
        if (i < mex) {
            ans2 += i * mp[i];
            if (mp[i] > 1) {
                mp[mex] += mp[i];
                mp[i] = 0;
            }
        }
        if (i > mex) {
            ans2 += i * mp[i];
            mp[mex] += mp[i];
            mp[i] = 0;
        }
    }
    mex = 0;
    while (mex <= n && mp[mex] > 0) mex++;
    for (i64 i = 0; i <= n; i++) {
        if (i < mex) {
            ans3 += i * mp[i];
            if (mp[i] > 1) {
                mp[mex] += mp[i];
                mp[i] = 0;
            }
        }
        if (i > mex) {
            ans3 += i * mp[i];
            mp[mex] += mp[i];
            mp[i] = 0;
        }
    }
    // cout << ans2 << " " << ans3 << endl;
    cout << (k - 1 & 1 ? ans3 : ans2) << endl;
}

void solve2()
{
    i64 n, k;
    cin >> n >> k;
    vint cnt(n + 1, 0);
    for (i64 i = 0; i < n; i++) {
        i64 p;
        cin >> p;
        cnt[p]++;
    }
    // 求出第一次的MEX
    i64 idx1 = 0;
    while (idx1 <= n && cnt[idx1] > 0) idx1++;
    i64 x1 = 0, pre = 0;
    // idx1 前的不会变化
    for (i64 i = 0; i < idx1; i++) {
        if (cnt[i] == 1) {
            x1++;
            pre += i;
        }
    }
    // cout << idx1 << endl;
    // mex后有多少元素
    i64 x2 = n - x1;
    i64 ans1 = pre + x2 * idx1;
    if (k == 1) {
        cout << ans1 << endl;
        return;
    }
    i64 idx2 = -1;
    for (i64 i = 0; i < idx1; i++) {
        if (cnt[i] >= 2) {
            idx2 = i;
            break;
        }
    }
    // cout << idx2 << endl;
    if (idx2 == -1) {
        i64 ans2 = pre + x2 * (idx1 + (x2 >= 2 ? 1 : 0));
        cout << (k & 1 ? ans1 : ans2) << endl;
        return;
    }
    else {
        i64 p = idx2 * (idx2 - 1) / 2;
        i64 ans2 = p + idx2 * (n - idx2);
        i64 ans3 = p + (idx2 + (n - idx2) * (n - idx2 >= 2 ? 1 : 0));
        i64 ans4 = p + (idx2 + 1) * (n - idx2);
        if (idx1 - idx2 == 1) {
            cout << ((k & 1) ? ans4 : ans2) << endl;
            return;
        }
        cout << ((k & 1) ? ans3 : ans2) << endl;
    }
}

// 正解
void solve3()
{
    i64 n, k;
    cin >> n >> k;
    vint v(n + 1, 0);
    for (i64 i = 0; i < n; i++) {
        i64 t;
        cin >> t;
        v[t]++;
    }
    // 如果mex = 0;
    if (v[0] == 0) {
        cout << (k & 1 ? 0 : n) << endl;
        return;
    }
    i64 mex = 0;
    i64 ans1 = 0, ans2 = 0, ans3 = 0;
    // 三个模拟,分别对应1,2,3次模拟的答案
    auto f = [&]() -> i64 {
        i64 res = 0;
        while (mex <= n && v[mex] > 0) mex++;
        for (i64 i = 0; i <= n; i++) {
            if (i < mex && v[i] == 1) {
                res += i;
            }
            // 大于1的值会在第一次变化变成mex
            if (i < mex && v[i] > 1) {
                res += mex * v[i];
                // 下一次变化后mex会增加,
                // 为什么是可行的?因为我们这次模拟并不经过mex,所以对mex上的值增加是无关的
                v[mex] += v[i];
                v[i] = 0;
            }
            if (i > mex) {
                res += v[i] * mex;
                v[mex] += v[i];
                v[i] = 0;
            }
        }
        // cout << res << endl;
        return res;
    };
    // 第一次变化
    ans1 = f();
    if (k == 1) {
        cout << ans1 << endl;
        return;
    }
    mex = 0;
    ans2 = f();
    mex = 0;
    ans3 = f();
    cout << (k & 1 ? ans3 : ans2) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve3();
    }
    return 0;
}