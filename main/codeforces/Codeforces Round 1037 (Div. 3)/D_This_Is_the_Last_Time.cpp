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

struct st
{
    int l, r, re;
};

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<st> v(n);
    for (size_t i = 0; i < n; i++)
    {
        auto &&[l, r, t] = v[i];
        cin >> l >> r >> t;
    }
    ranges::sort(v, [](st a, st b) { return a.l < b.l; });
    priority_queue<pii> pq;
    int now = k;
    int idx = 0;
    while (1)
    {
        while (idx < n && v[idx].l <= now)
        {
            pq.emplace(v[idx].re, v[idx].r);
            idx++;
        }
        // 排除 r < now的
        while (!pq.empty() && pq.top().second < now)
        {
            pq.pop();
        }
        // 如果空或者没有比x大的,那么就退出
        if (pq.empty() || pq.top().first <= now) {
            break;
        }
        // 提升now
        now = pq.top().first;
        pq.pop();
    }
    cout << now << endl;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}