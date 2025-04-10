//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


//更为简洁的求LIS算法
int Lis(vint v)
{
    vint res;
    for (auto &&i : v) {
        auto it = lower_bound(all(res), i);
        if (it == res.end())
            res.emplace_back(i);
        else
            *it = i;
    }
    return res.size();
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    vint v(T);
    vint last_num(T, 0);
    for (auto &&i : v) {
        cin >> i;
    }
    // LIS
    // 这里的二分查找的是在last_num数组里当前 v[i] 应该被放入的位置
    // 就相当于使用 v 数组内的元素构建一个最长的上升序列
    // 其中二分查找结束后的 r 指向恰好比 v[i] 小的一个数的
    int len = 0;
    for (size_t i = 0; i < T; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (last_num[mid] < v[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        last_num[r + 1] = v[i];
    }
    cout << Lis(v) << endl;
    last_num.erase(last_num.begin());
    for (auto &&i : last_num) {
        cout << i << " ";
    }
    return 0;
}