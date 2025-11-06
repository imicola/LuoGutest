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

/* 
    显然因为题目要求，我们可以从最开始的状态直接推导到结束态
    因为不可能三个连线，最后结果则一定是从第一个开始黑色的斜向下的线，而所有的黑色块都要在这个线中
    而开始方向则是左右各自模拟一次即可。
    我们怎么判断所有黑子在黑线上？
*/

void solve()
{
    i64 n;
    cin >> n;
    vvint mp(n + 1, vint(n + 1));
    i64 noblack = 1;
    i64 b_idx1 = 0, b_idx2 = 0;
    i64 b_idx3 = 0, b_idx4 = 0;
    i64 cntb = 0;
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            char c;
            cin >> c;
            mp[i][j] = (c == '.' ? 1 : 2);
            if (c == '#') cntb++;
            if (c == '#' && noblack) {
                noblack = 0;
                b_idx1 = i;
                b_idx2 = j;
            }
        }
    }
    // 特判
    if (b_idx1 + 1 <= n && b_idx2 + 1 <= n) {
        if (mp[b_idx1][b_idx2] == 2 && mp[b_idx1 + 1][b_idx2] == 2 && mp[b_idx1 + 1][b_idx2 + 1] == 2 &&
            mp[b_idx1][b_idx2 + 1] == 2 && cntb == 4) {
            cout << "YES" << endl;
            return;
        }
        if (cntb == 3) {
            if (mp[b_idx1][b_idx2] == 2 && mp[b_idx1 + 1][b_idx2] == 2 && mp[b_idx1][b_idx2 + 1] == 2) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    // 没有黑色，一定可行
    if (noblack) {
        cout << "YES" << endl;
        return;
    }
    // 正方形块

    // 向右下
    i64 cnt1 = 0, cnt2 = 0;
    for (i64 i = 0, j = 0; i + b_idx1 <= n && j + b_idx2 <= n; i++, j++) {
        i64 r = i + b_idx1, c = j + b_idx2;
        i64 k1 = mp[r][c];
        i64 k1r = 0;
        i64 k1d = 0;
        if (r + 1 <= n) {
            k1d = mp[r + 1][c];
        }
        if (c + 1 <= n) {
            k1r = mp[r][c + 1];
        }
        if (k1 == 2) {
            cnt1++;
            cnt2++;
        }
        if (k1r == 2) {
            cnt1++;
        }
        if (k1d == 2) {
            cnt2++;
        }
    }
    if (cnt1 == cntb || cnt2 == cntb) {
        cout << "YES" << endl;
        return;
    }
    // 向左下,注意起点变化
    for (i64 i = 1; i <= n; i++) {
        i64 ok = 0;
        for (i64 j = n; j >= 1; j--) {
            if (mp[i][j] == 2) {
                b_idx3 = i;
                b_idx4 = j;
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }
    cnt1 = cnt2 = 0;
    for (i64 i = 0, j = 0; i + b_idx3 <= n && b_idx4 - j >= 1; i++, j++) {
        i64 r = i + b_idx3, c = b_idx4 - j;
        i64 k1 = mp[r][c];
        i64 k1l = 0;
        i64 k1d = 0;
        if (r + 1 <= n) {
            k1d = mp[r + 1][c];
        }
        if (c - 1 >= 1) {
            k1l = mp[r][c - 1];
        }
        if (k1 == 2) {
            cnt1++;
            cnt2++;
        }
        if (k1l == 2) {
            cnt1++;
        }
        if (k1d == 2) {
            cnt2++;
        }
    }
    if (cnt1 == cntb || cnt2 == cntb) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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