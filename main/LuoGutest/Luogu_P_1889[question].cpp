//#pragma GCC optimize(3)
#include <bits/stdc++.h>
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

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vint x(n);
    vint y(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(all(y));
    sort(all(x));
    int midy = 0;
    if (n % 2 == 0)
        midy = (y[n / 2] + y[n / 2 - 1]) / 2;
    else
        midy = y[n / 2];
    // cout << midy;
    // midy = y[n / 2];
    int ansy = 0;
    for (int i = 0; i < n; i++) ansy += abs(y[i] - midy);
    int ansx = 1e7;
    int s = x[0] + n;
    int t = x[0] - n;
    for (size_t i = t - 10; i <= s + 100; i++) {
        int temp = 0;
        for (size_t j = 0; j < n; j++) {
            temp += abs(x[j] - (i + j));
        }
        ansx = min(ansx, temp);
    }
    //对x上的计算的解释: 排序后的x[0]为坐标的最小值，此时要是将x[0]到x[n-1]全部排下来，最坏的情况是a[0]向左边移动n个距离，或n移动到靠近中位数的位置
    //则这一串士兵的排序头区间在[a[0]-n,a[0]+n];
    // --> i 表示排序的头，即a[0]所处的位置
    // --> (i+j) 表示每个士兵要移动到的位置,因为数组x已经被排序过了，所以在排序头确定的情况下最短距离即为x[j]到 i + j 的距离
    // --> 因为每一个排序头都有可能成为答案，所以要维护一个最小值作为最终答案
    cout << ansx + ansy;
    return 0;
}
// 题解思路有问题，会WA两个点
// 不对啊，我草，好诡异啊
// 为什么啊？