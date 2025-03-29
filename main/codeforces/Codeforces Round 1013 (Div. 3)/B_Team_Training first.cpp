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

void solve()
{
    int n, x;
    cin >> n >> x;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    ranges::sort(v, greater<int>());
    int ans = 0, index = INT32_MAX;
    for (size_t i = 0; i < n; i++) {
        if (v[i] >= x) {
            ans++;
        }
        if (v[i] < x) {
            index = i;
            break;
        }
    }
    // cout << index << endl;
    vint temp;
    for (size_t i = index; i < n; i++) {
        temp.emplace_back(v[i]);
        if (*ranges::min_element(temp) * temp.size() >= x) {
            ans++;
            temp.clear();
        }
    }
    cout << ans << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}