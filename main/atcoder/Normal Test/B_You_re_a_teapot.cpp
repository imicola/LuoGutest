//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
#define double long double
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
    // t > 3 -> 100%
    for (size_t i = 0; i < s.size(); i++) {
        int k = 0;
        while (i < s.size() && s[i] == 't') {
            i++;
            k++;
        }
        if (k > 2) {
            cout << 1 << endl;
            return;
        }
    }
    // t < 3
    double res = 0;
    for (size_t i = 0; i < s.size(); i++) {
        while (i < s.size() && s[i] != 't') {
            i++;
        }
        // cout << i << endl;
        double cntt = 0, cnt = 0;
        for (size_t j = i; j < s.size(); j++) {
            if (s[j] == 't') cntt++;
            cnt++;
            if (cntt > 2) res = max(res, (cntt - 2) / (cnt - 2));
        }
    }
    cout << res << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(17);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}