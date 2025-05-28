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
    string s;
    cin >> s;
    // cout << s << endl;
    if (s.front() == s.back() || n == 2) {
        cout << (s.front() == 'A' ? "Alice" : "Bob") << endl;
        return;
    }
    int cntA = 0, cntB = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'A') cntA++;
        if (s[i] == 'B') cntB++;
    }
    // 神秘答案
    // cout << cntB << endl;
    if (cntB == 1) {
        cout << "Alice" << endl;
        return;
    }
    if (cntB > 1 && (s.back() == 'B')) {
        cout << "Bob" << endl;
        return;
    }
    char sback = s[n - 2];
    if (s.back() == 'A' && sback == 'A') {
        cout << "Alice" << endl;
        return;
    }
    if (s.back() == 'A' && sback == 'B') {
        cout << "Bob" << endl;
        return;
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