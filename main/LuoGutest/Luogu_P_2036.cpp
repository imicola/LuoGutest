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

int T;
vpii food;
// vint result;
int ans = 1e6;

void dfs(int n, int sum_s, int sum_k)
{
    if (n == T) {
        sum_s *= food[n - 1].first;
        sum_k += food[n - 1].second;
        ans = min(ans, abs(sum_s - sum_k));
        return;
    }
    sum_s *= food[n].first;
    sum_k += food[n].second;
    ans = min(ans, abs(sum_s - sum_k));
    for (size_t k = 0; k < T; k++) {
        for (size_t i = n; i < T; i++) {
            dfs(i + 1, sum_s, sum_k);
        }
        sum_s = 1;
        sum_k = 0;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> T;
    food = vpii(T);
    // result = vint(T, 0);
    for (auto &&[s, k] : food) {
        cin >> s >> k;
    }
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}
// 比我命还暴力这个算法
// 这题绝对能用DP写，待我研究一下