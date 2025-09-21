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

i64 getx(i64 x)
{
    return (x + 8) % 9 + 1;
}

void solve()
{
    string s;
    cin >> s;
    i64 len = s.size();
    i64 ans = 0, sum = 0;
    i64 cnt = 0;
    string s1;
    for (i64 i = 0; i < len; i++) {
        s1 += s[i];
        i64 p = getx(stoll(s1));
        s1 = to_string(p);
        ans += (s[i] ^ 48) * (i + 1);
        sum += ans;
        cout << ans << endl;
    }
    cout << sum << endl;
}
/*


*/
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