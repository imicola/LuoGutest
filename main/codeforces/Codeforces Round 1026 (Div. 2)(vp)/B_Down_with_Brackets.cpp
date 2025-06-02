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
    string s;
    cin >> s;
    //判题机似了，此行无用
    if (s.size() <= 2) {
        cout << "NO" << endl;
        return;
    }
    stack<pair<char, int>> sk;
    int cnt = 0;
    vint v(s.size());
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            v[i] = sk.top().second;
            cnt++;
            sk.pop();
            continue;
        }
        sk.push({v[i], cnt});
    }
    if (v.back() == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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