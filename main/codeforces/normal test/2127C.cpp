//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint a(n), b(n);
    i64 sumA = 0, sumB = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
    }
    /* 
        A希望最小化v,B希望最大化v
        每次可行的操作是A选择两个下标，B决定是否交换和如何交换
        v的含义是两数组同下标的差值，如果这次交换可以增加差值，则B会决定交换，否则不会
        由于是A先选择
        猜测大概率只会交换一次，然后由于这组达到平衡，A为了减少差值增加只会不断重复选择第一组
        那第一次的选择一定是无论如何交换都不会让差增加或增加的最少的
        
        b的策略是每次选择将a选的四个数分为两个差值最大的组放入
        则我们需要选择最大的两个数之和与最小两个数之和的差尽量小
        怎么做呢？
    */
    vint diffab(n), diffab2(n);
    i64 cnt = 0;
    for (i64 i = 0; i < n; i++) {
        diffab[i] = abs(a[i] - b[i]);
        cnt += diffab[i];
    }
    // cout << cnt <<endl;
    sort(all(a)), sort(all(b));
    for (i64 i = 0; i < n; i++) {
        diffab2[i] = abs(a[i] - b[i]);
    }
    sort(all(diffab2)), sort(all(diffab));
    if (diffab != diffab2) {
        cout << cnt << endl;
        return;
    }
    i64 Min = LLONG_MAX;
    for (i64 i = 0; i + 1 < n; i++) {
        vint v = {a[i], a[i + 1], b[i], b[i + 1]};
        i64 diff = abs(a[i] - b[i]) + abs(a[i + 1] - b[i + 1]);
        sort(all(v));
        i64 k = v[3] - v[0] + v[2] - v[1];
        Min = min(Min, abs(k - diff));
    }
    cout << cnt + Min << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}