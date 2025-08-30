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
    int l, r;
    cin >> l >> r;
    // f(l,x) + f(x,r) min
    string s1 = to_string(l);
    string s2 = to_string(r);
    int pre = 0;
    int cnt = 0;
    while (pre < s1.size() && s1[pre] == s2[pre]) pre++;
    if (abs(s1[pre] - s2[pre]) > 1 || pre == s1.size()) {
        cout << 2 * pre << endl;
        return;
    }
    int idx = pre + 1;
    while (idx < s1.size() && s1[idx] == '9' && s2[idx] == '0') {
        cnt++;
        idx++;
    }
    cout << pre * 2 + cnt + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}