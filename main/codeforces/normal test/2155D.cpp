//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl '\n'
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
    auto ask = [](i64 u, i64 v) -> void { cout << u << " " << v << endl; };
    /* 
        我们一次可以找到选择两节电池验证
        突破点在 n*n / a 这里
        这意味着我们可能不能用n^2的方法来决定
        能不能用随机算法(?)
        显然不行 wa on 1
        交互器的策略是让我们无法构成有效电池对
    */
    // 我们从固定点转化为固定步长
    // i是向前移动的步数
    for (i64 i = 1; i < n; i++) {
        for (i64 j = 1; j <= n; j++) {
            i64 k = (i + j) % n;
            if (k == 0) k = n;
            ask(j, k);
            i64 res;
            cin >> res;
            if (res) return;
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}