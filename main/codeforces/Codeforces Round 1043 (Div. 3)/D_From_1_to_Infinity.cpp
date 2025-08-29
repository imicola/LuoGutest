//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int ksm(int a, int b)
{
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int f(int x, int fk)
{
    if (x == 1) {
        return (fk) * (fk - 1) / 2;
    }
    int res = 0;
    int k = f(x - 1, 10);
    if (fk == 10) {
        for (size_t i = 1; i < fk; i++) {
            res += (ksm(10, x - 1) * i);
        }
    }
    else {
        for (size_t i = 1; i <= fk; i++) {
            res += (ksm(10, x - 1) * i);
        }
    }
    // cout << "idx " << x << " res " << res + fk * k << endl;
    return res + fk * k;
}
// 1 2 3 4 5 ... 9 --> 45 + 0
// 10 11 .. 19 -> 45 + 10

// n   表示目前迭代的数字
// idx 表示n当前有几位
int re(int n, int idx)
{
    if (idx == 1) {
        int res = 0;
        return (n - 1) * n / 2;
    }
    // 初始迭代，确定初始n的idx
    if (idx == -1) {
        vector<int> q;
        idx = 0;
        int sum = 0;
        while (sum < n) {
            sum += 9 * ksm(10, idx - 1) * idx;
            q.emplace_back(sum);
            if (sum >= n) break;
            idx++;
        }
        // x表示前面位数
        int x = idx - 1;
        int ans = 0;
        // f(x)表示所有小于n位数的数字加和
        ans += f(x, 10);
        // p 表示除去n前面的还剩多少
        int p = n - q[x];
        // 迭代
        // cout << "-1 ans " << ans << " idx " << idx << " p " << p << endl;
        return ans + re(p, idx);
    }
    int sum = 0;
    // 找n在idx - 1分块的第几个块
    int p = ksm(10, idx - 1) * idx;
    // 如果在第一个块
    if (n <= p) {
        int ress = (n + idx - 1) / idx;
        // cout << "p " << p << " n " << n << " ress " << ress << " idx " << idx << endl;
        return ress + re((n - ress), idx - 1);
    }
    int ndx = 0;
    int ans = 0;
    vector<int> q;
    while (sum < n) {
        sum += p;
        q.emplace_back(sum);
        if (sum >= n) break;
        ndx++;
    }
    ans += f(idx, ndx - 1);
    int p2 = n - q[ndx - 1];
    int ress = ((p2 + idx - 1) / idx) * ndx;
    // cout << "n " << n << " p2 " << p2 << " ress " << ress << " ndx " << ndx << " idx " << idx << endl;
    return ans + ress + re(p2 - (ress / ndx), idx - 1);
}

void solve()
{
    int n;
    cin >> n;
    if (n < 10) {
        cout << ((1 + n) * (n)) / 2 << endl;
        return;
    }
    // int idx = 0, sum = 0;
    // // 确定所指的数在idx的第几位
    // vector<int> q;
    // while (sum < n) {
    //     sum += 9 * ksm(10, idx - 1) * idx;
    //     q.emplace_back(sum);
    //     if (sum >= n) break;
    //     idx++;
    // }
    // // for (auto &&i : q)
    // // {
    // //     cout << i << ' ';
    // // }
    // // cout << endl;
    // int x = idx - 1;
    // int ans = 0;
    // ans += f(x);
    // int p = n - q[x];
    cout << re(n, -1) << endl;
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