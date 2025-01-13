//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    multimap<int, int> mp;
    for (size_t i = 1; i <= T; i++) {
        int t = 0;
        cin >> t;
        mp.emplace(t, i);
    }
    vint res;
    int sum = 0;
    for (auto &&[val, index] : mp) {
        cout << index << " ";
        res.emplace_back(val);
    }
    for (size_t i = 1; i < T; i++) {
        res[i] += res[i - 1];
        sum += res[i - 1];
    }
    // sum += res[0];
    printf("\n%.2f", sum / (T * 1.0));
    return 0;
}
// 无语，和你这种典型贪心思想聊不上一点
// 时间排序是由小到大，至于为什么？ 可以这样理解
// 假设现在有两个时间 t1 = 1 & t2 = 1000;
// 若排序 t1 t2 ==> 每个人的等待时间为 0 1 , 平均为0.50
// 若排序 t2 t1 ==> 则为 0 1000 ，平均为500.00
// 显然，我们要让时间长的尽量后移，防止时间长的接水对其排后面的人时间压力