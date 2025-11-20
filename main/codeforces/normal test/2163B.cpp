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
    i64 n;
    cin >> n;
    vint v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
    }
    string x;
    cin >> x;
    if (x.front() == '1' || x.back() == '1') {
        cout << -1 << endl;
        return;
    }
    if (x.find('1') == string::npos) {
        cout << 0 << endl;
        return;
    }
    /* 
        最大最小的元素不能是1
        数组边界元素不能是1
        每一次选取边界，我们都希望这两个元素之差尽可能大且距离尽可能远
        有点神秘啊这个
        对于xi为1的位置是，其含义是需要我们找到两个元素使得其这个元素包含在区间内且在边界元素的值域内
        我们思考是从x -> s or 5次构造出含最多1的s？
        我们思考最大选取能否可行
        5次限定是什么意思呢？
        最大选取思路
        边界 + 最大最小
        正好可以凑出5组，正好满足题目条件
    */
    i64 idx1 = find(all(v), 1) - v.begin();
    i64 idx2 = find(all(v), n) - v.begin();
    bool ok = 1;
    string s(n, '0');
    // case1 1 ~ min
    for (i64 i = 0; i < idx1; i++) {
        if (v[i] > 1 && v[i] < v.front()) {
            s[i] = '1';
        }
    }
    // case2 1 ~ max
    for (i64 i = 0; i < idx2; i++) {
        if (v[i] > v.front() && v[i] < n) {
            s[i] = '1';
        }
    }
    // case3 min ~ n
    for (i64 i = idx1; i < n; i++) {
        if (v[i] > 1 && v[i] < v.back()) {
            s[i] = '1';
        }
    }
    // case4 max~n
    for (i64 i = 0; i < n; i++) {
        if (v[i] < n && v[i] > v.back()) {
            s[i] = '1';
        }
    }
    // case5 min~max
    if (idx1 > idx2) swap(idx1, idx2);
    for (i64 i = idx1; i <= idx2; i++) {
        if (v[i] > 1 && v[i] < n) {
            s[i] = '1';
        }
    }
    for (i64 i = 0; i < n; i++) {
        if (x[i] == '1' && s[i] != '1') ok = 0;
    }
    if (ok) {
        cout << 5 << endl;
        cout << 1 << " " << idx1 + 1 << endl;
        cout << 1 << " " << idx2 + 1 << endl;
        cout << idx1 + 1 << " " << n << endl;
        cout << idx2 + 1 << " " << n << endl;
        cout << idx1 + 1 << " " << idx2 + 1 << endl;
    }
    else {
        cout << -1 << endl;
    }
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