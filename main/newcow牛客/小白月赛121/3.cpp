//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    map<i64, i64> mp;
    for (auto &&i : s) {
        mp[(i ^ 48)]++;
    }
    if (mp.contains(0)) {
        cout << 0 << endl;
        return;
    }
    i64 cnt = 1;
    for (i64 i = 1; i < 1e6; i++) {
        map<i64, i64> ch = mp;
        i64 check = i * d;
        string s2 = to_string(check);
        i64 ok = 1;
        for (auto &&j : s2) {
            if (ch[(j ^ 48)] == 0) ok = 0;
            ch[(j ^ 48)]--;
        }
        if (ok) {
            cout << check << endl;
            return;
        }
    }
    cout << -1 << endl;
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