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

void solve()
{
    int n;
    cin >> n;
    vint a(2 * n);
    for (auto &&i : a) {
        cin >> i;
    }
    vint res(2 * n, 0);
    vint ans;
    set<int> path;
    for (auto &&i : a) {
        if (!path.contains(i)) {
            path.insert(i);
            for (auto &&k : path) {
                res[k]++;
            }
        }
        else {
            for (auto &&k : path) {
                res[k]++;
            }
            ans.emplace_back(res[i]);
        }
    }
    cout << ranges::max(ans);
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