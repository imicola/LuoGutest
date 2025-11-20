//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << -1 << endl;
        return;
    }
    stack<char> sk;
    i64 cnt = 0, cnt2 = 0;
    for (auto &&i : s) {
        if (i == '(') {
            sk.push('(');
        }
        else {
            if (sk.empty())
                cnt++;
            else {
                sk.pop();
            }
        }
    }
    if (!sk.empty()) cnt2 += sk.size();
    // cnt += sk.size();
    cout << (cnt + 1) / 2 + (cnt2 + 1) / 2 << endl;
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