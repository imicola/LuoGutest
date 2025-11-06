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
    显然，如果我们能凑出一对相同的，则在这对相同的之前的就可以全部变为相等的
    则我们策略是尽可能向后找可以凑出相同的
    可行的策略有两种
    我们设需要凑出相同的数字为 k
    如果两个k在同一数组，则k之间需要距离为奇数
    如果在不同的数组，则距离要为偶数

    删去一个下标的作用是什么呢？
    可以让大于1或2的数改变奇偶性
    那就是找相同的数即可？注意排除不同数组相距为1的
*/
void solve()
{
    i64 n;
    cin >> n;
    vint a(n), b(n);
    for (auto &&i : a) cin >> i;
    for (auto &&i : b) cin >> i;
    map<i64, pii> mp; // [i,[j,k]] 表示数字i在下标为j的k数组中出现过
    // i64 ans = 0;
    for (i64 i = n - 1; i >= 0; i--) {
        i64 numa = a[i];
        i64 numb = b[i];
        if (numa == numb) {
            cout << i + 1 << endl;
            return;
        }
        i64 ok = 0;
        auto itA = mp.find(a[i]);
        if (itA != mp.end()) {
            auto [j, k] = itA->second;
            if (!(j == i + 1 && k == 2)) ok = 1;
        }
        auto itB = mp.find(b[i]);
        if (itB != mp.end()) {
            auto [j, k] = itB->second;
            if (!(j == i + 1 && k == 1)) ok = 1;
        }
        if (ok) {
            cout << i + 1 << endl;
            return;
        }
        auto it = mp.find(numa);
        if (it == mp.end() || it->second.first < i) mp[numa] = {i, 1};
        it = mp.find(numb);
        if (it == mp.end() || it->second.first < i) mp[numb] = {i, 2};
    }
    cout << 0 << endl;
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