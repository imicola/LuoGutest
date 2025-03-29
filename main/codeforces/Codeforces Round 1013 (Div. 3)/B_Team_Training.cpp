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
    for (size_t i = index; i < n;) {
        int cnt = 0;
        int minn = v[i];
        while (cnt * minn < x && i + cnt < n) {
            cnt++;
            minn = min(minn, v[i + cnt - 1]);
        }
        if (cnt * minn >= x) {
            ans++;
            i += cnt;
        }
        else {
            i++;
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