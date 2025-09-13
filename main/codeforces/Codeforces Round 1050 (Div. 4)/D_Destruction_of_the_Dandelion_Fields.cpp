//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    vint odd, even;
    i64 sum = 0;
    for (i64 i = 0; i < n; i++) {
        i64 t = 0;
        cin >> t;
        if (t & 1)
            even.push_back(t);
        else {
            odd.push_back(t);
            sum += t;
        }
    }
    ranges::sort(even);
    if (even.size() == 0) {
        cout << 0 << endl;
        return;
    }
    i64 k = even.size() / 2;
    for (int i = even.size() - 1; i >= k; i--) {
        sum += even[i];
    }
    cout << sum << endl;
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