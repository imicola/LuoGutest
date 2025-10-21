//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    i64 cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            i64 p = 1;
            i64 ok = 1;
            while (i - p >= 0 && p < k) {
                if (s[i - p] == '1') ok = 0;
                p++;
            }
            if (ok) cnt++;
        }
    }
    cout << cnt << endl;
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