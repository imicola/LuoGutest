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
    map<int, int> mp;
    vint v(n);
    int y = 0, d = 0, g = 0, cnt = 0;
    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        v[i] = t;
        mp[t]++;
        if (mp[t] == 2) {
            cnt++;
            if (cnt == 2) {
                d = t;
                g = t;
                continue;
            }
            y = t;
        }
        if (mp[t] == 4) {
            d = t, g = t, y = t;
        }
    }
    if (d != 0) {
        cout << y << " " << y << " " << d << " " << g << endl;
        return;
    }
    if (y == 0) {
        cout << -1 << endl;
        return;
    }
    int diffmin = INT_MAX;
    v.erase(remove(all(v), y), v.end());
    if (mp[y] == 3) {
        v.emplace_back(y);
    }
    ranges::sort(v);
    for (int i = 0; i + 1 < v.size(); i++) {
        if (v[i + 1] - v[i] < diffmin) {
            d = v[i + 1];
            g = v[i];
            diffmin = v[i + 1] - v[i];
        }
    }
    if (g + y * 2 <= d) {
        cout << -1 << endl;
    }
    else {
        cout << y << " " << y << " " << d << " " << g << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}