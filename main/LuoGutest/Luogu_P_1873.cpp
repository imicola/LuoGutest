//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
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
    int n, m;
    cin >> n >> m;
    vint tree(n);
    for (auto &&i : tree) {
        cin >> i;
    }
    sort(all(tree));
    int l = 1, r = tree.back(), mid = (l + r) / 2, ans = 0;
    while (l < r) {
        for (auto &&i : tree) {
            ans += (i - mid > 0 ? i - mid : 0);
        }
        // cout << l << " " << r << " " << mid << " " << ans << endl;
        if (ans > m) {
            l = mid;
            mid = (l + r) / 2;
        }
        if (ans < m) {
            r = mid;
            mid = (l + r) / 2;
        }
        if (ans == m) {
            break;
        }
        ans = 0;
    }
    cout << mid;
    return 0;
}