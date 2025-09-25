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
    i64 n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<i64> a;
    for (i64 i = 0; i < m; i++) {
        i64 x;
        cin >> x;
        a.insert(x);
    }
    i64 cur = 1;
    for (auto &&i : s) {
        cur++;
        if (i == 'B') {
            while (a.contains(cur)) cur++;
        }
        a.insert(cur);
        if (i == 'B') {
            while (a.contains(cur)) cur++;
        }
    }
    cout << a.size() << endl;
    for (auto &&i : a) {
        cout << i << " ";
    }
    cout << endl;
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