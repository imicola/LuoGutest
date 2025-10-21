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
    i64 n;
    cin >> n;
    vint v(n + 1);
    map<i64, i64> mp;
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin() + 1, v.end(), greater<i64>{});
    vint pre(n + 1);
    pre[0] = 0;
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    /* 
        给定n个长度,求选k in 1-n 中数k个数可以组成的凸多边形的最大结果
        先找最大的结果为3的，小边是一定可以被加入的
        大边则看看能不能加入小边后超过大边

    */
    //#pragma GCC optimize(3)

    i64 n;
    cin >> n;
    vint v(n + 1);
    map<i64, i64> mp;
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin() + 1, v.end(), greater<i64>{});
    vint pre(n + 1);
    pre[0] = 0;
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    /* 
        给定n个长度,求选k in 1-n 中数k个数可以组成的凸多边形的最大结果
        先找最大的结果为3的，小边是一定可以被加入的
        大边则看看能不能加入小边后超过大边
        
        贪心好像不行
        试试二分
    */
    // 预处理每个起点 s 的最小可行长度L
    vvint vv(n + 2);
    for (i64 s = 1; s <= n; s++) {
        i64 tar = pre[s] + v[s];
        auto it = upper_bound(pre.begin() + s + 1, pre.begin() + n + 1, tar);
        if (it == pre.begin() + n + 1) continue;
        i64 r = it - pre.begin();
        i64 L = max(3ll, r - s + 1);
        if (L <= n) vv[L].push_back(s);
    }
    vint ans(n + 1, 0);
    priority_queue<i64, vint, greater<i64>> pq;
    for (i64 len = 3; len <= n; len++) {
        for (auto &&s : vv[len]) pq.push(s);
        while (!pq.empty() && pq.top() > n - len + 1) pq.pop();
        if (!pq.empty()) {
            i64 s = pq.top();
            ans[len] = pre[s + len - 1] - pre[s - 1];
        }
        else {
            ans[len] = 0;
        }
    }

    for (i64 i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void solve2()
{
    i64 n;
    cin >> n;
    vint v(n + 1);
    map<i64, i64> mp;
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin() + 1, v.end(), greater<i64>{});
    vint pre(n + 1);
    pre[0] = 0;
    for (i64 i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    /* 
        给定n个长度,求选k in 1-n 中数k个数可以组成的凸多边形的最大结果
        先找最大的结果为3的，小边是一定可以被加入的
        大边则看看能不能加入小边后超过大边

    */
    vint ans(n + 1, 0);
    for (i64 len = 3; len <= n; len++) {
        i64 best = 0;
        for (i64 k = 1; k + len - 1 <= n; k++) {
            if (v[k] < pre[k + len - 1] - pre[k]) {
                best = k;
                break;
            }
        }
        if (best) {
            ans[len] = pre[best + len - 1] - pre[best - 1];
        }
        else {
            ans[len] = 0;
        }
    }
    for (i64 i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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