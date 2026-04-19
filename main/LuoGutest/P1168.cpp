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
    priority_queue<i64> bpq;  
    priority_queue<i64, vint, greater<i64>> spq;
    for (i64 i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        if (i == 1) {
            bpq.push(x);
            cout << x << endl;
            continue;
        }
        // 确保所有元素都被加入某个堆
        if (spq.empty() || x <= spq.top()) {
            bpq.push(x);
        } else {
            spq.push(x);
        }
        if (bpq.size() < spq.size()) {
            i64 tmp = spq.top();
            spq.pop();
            bpq.push(tmp);
        } else if (bpq.size() > spq.size() + 1) {
            i64 tmp = bpq.top();
            bpq.pop();
            spq.push(tmp);
        }
        if (i % 2 == 1) {
            cout << bpq.top() << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}