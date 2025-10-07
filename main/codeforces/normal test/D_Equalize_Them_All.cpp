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
    vint v(n);
    map<i64, i64> mp;
    i64 Max = 0;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        if (mp[v[i]] > mp[Max]) {
            Max = v[i];
        }
    }
    cout << n - mp[Max] << endl;
    i64 idx = find(all(v), Max) - v.begin();
    auto put1 = [&](i64 x) { cout << "2 " << x + 1 << " " << x << endl; };
    auto put2 = [&](i64 x) { cout << "1 " << x + 1 << " " << x << endl; };
    auto put3 = [&](i64 x) { cout << "2 " << x << " " << x + 1 << endl; };
    auto put4 = [&](i64 x) { cout << "1 " << x << " " << x + 1 << endl; };
    for (i64 i = idx + 1; i < n; i++) {
        if (v[i] > Max) put1(i);
        if (v[i] < Max) put2(i);
    }
    for (i64 i = idx - 1; i >= 0; i--) {
        if (v[i] > Max) put3(i + 1);
        if (v[i] < Max) put4(i + 1);
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}