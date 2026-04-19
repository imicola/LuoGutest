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

8 1
1 0 1 0 1 1 0 1  [2 7]
1 1 0 1 0 0 1 1  [3 6]
1 1 1 0 1 1 1 1
1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1

6 1 3
0 1 0 1 0 1
0 0 1 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 0
*/

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint v(n);
    vint vk(k);
    for (auto &&i : v) {
        cin >> i;
    }
    for (auto &&i : vk) {
        cin >> i;
    }
    i64 cur = vk.front() - 1;
    i64 tar = v[cur];
    i64 l = 0, r = n - 1;
    i64 curr = tar;
    i64 ans1 = 0, ans2 = 0;
    while (v[l] == curr) {
        l++;
    }
    for (; l <= cur; l++) {
        while (v[l] == curr) {
            l++;
        }
        if (l > cur) break;
        ans1++;
        curr = (!curr);
    }
    curr = tar;
    while (v[r] == curr) {
        r--;
    }
    for (; r >= cur; r--) {
        while (v[r] == curr) {
            r--;
        }
        if (r < cur) break;
        ans2++;
        curr = (!curr);
    }
    cout << max(ans1, ans2) << endl;
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