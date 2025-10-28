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
    vpii v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(all(v), [](auto a, auto b) { return a.first < b.first; });
    vint pre(n);
    pre[0] = v[0].first;
    for (i64 i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i].first;
    }
    /* 
        一个玩家赢面最大的情况是什么？
        先和比他小的都对战，然后不断累加自己
        继续和大的对战
        我们关注和大的对战
        只要某一个大的小于其前缀和即： 
        v[i] <= pre[i - 1]
        则可以被吃掉
        那我们就是找最后一个满足这个情况的，在这之后的一定可以获胜
    */
    vint ans;
    ans.reserve(n + 1);
    i64 idx = 0;
    for (i64 i = 1; i < n; i++) {
        if (v[i].first > pre[i - 1]) idx = i;
    }
    for (i64 i = idx; i < n; i++) {
        ans.emplace_back(v[i].second);
    }
    sort(all(ans));
    cout << ans.size() << endl;
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
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