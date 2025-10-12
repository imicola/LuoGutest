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
    vint v;
    for (i64 i = 0; i < 32; i++) {
        v.emplace_back(((n >> i) & 1));
    }
    reverse(all(v));
    while (!v.empty() && (*v.begin()) == 0) {
        v.erase(v.begin());
    }
    reverse(all(v));
    if (v.empty()) {
        cout << "YES" << endl;
        return;
    }
    i64 cnt = 0;
    while (v[cnt] == 0) {
        cnt++;
        v.emplace_back(0);
    }

    i64 len = v.size();
    if (len & 1) {
        i64 mid = len / 2;
        if (v[mid] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    i64 l = 0, r = len - 1, ok = 1;
    while (l < r) {
        if (v[l] != v[r]) ok = 0;
        l++, r--;
    }
    cout << (ok ? "YES" : "NO") << endl;
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