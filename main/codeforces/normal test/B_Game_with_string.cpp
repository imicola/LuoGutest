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
    string s;
    cin >> s;
    i64 n = s.size();
    stack<i64> sk;
    i64 cnt = 0;
    for (auto &&i : s) {
        if (sk.empty()) {
            sk.emplace(i);
        }
        else {
            if (sk.top() == i) {
                sk.pop();
                cnt++;
            }
            else {
                sk.emplace(i);
            }
        }
    }
    cout << (cnt & 1 ? "Yes" : "No") << endl;
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