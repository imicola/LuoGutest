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
    string s;
    cin >> s;
    s = "1" + s + "1";
    i64 cnt0 = 0;
    vint res(n + 1);
    for (i64 i = 0; i <= n; i++) {
        if (s[i] == '1') {
            res[i] = i;
            i64 k = i + 1;
            while (k <= n && s[k] == '0') {
                res[k] = k + 1;
                k++;
            }
            i64 len = k - i - 1;
            if (len == 0) continue;
            if (len == 1) {
                cout << "NO" << endl;
                return;
            }
            res[k - 1] = i + 1;
        }
    }
    cout << "YES" << endl;
    for (i64 i = 1; i <= n; i++) {
        cout << res[i] << " ";
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