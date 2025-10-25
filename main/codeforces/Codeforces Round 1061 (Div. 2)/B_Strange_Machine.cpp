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
    i64 n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vint v1, cnt; // v1操作,cnt步数0 - 1,1 /2
    // v1.emplace_back(s[0] == 'A' ? 0 : 1);
    // cnt[0] = 1;
    i64 cur = 0;
    i64 a = 0, b = 0, cntb = 0;
    i64 c = 0;
    for (i64 i = 0; i < n; i++) {
        if (s[i] == 'A') {
            c -= 1;
        }
        else {
            a += (1LL << b) * c;
            b++;
            c = 0;
            cntb++;
        }
    }
    i64 p = (1 << b);
    while (q--) {
        i64 x;
        cin >> x;
        if (b == 0) {
            cout << x << endl;
            continue;
        }
        i64 ans = 0;
        auto f = [&](i64 k1, i64 k2) -> i64 {
            if (k1 >= 0)
                return (k1 / k2);
            else
                return (-((1 - k1 + k2) / k2));
        };
        for (i64 i = 0; i < 100; i++) {
            i64 num = x + a;
            i64 k = f(num, p) + c;
            if (k > 0) {
                x = k;
                ans += n;
            }
            else {
                break;
            }
        }
        i64 i = 0;
        while (x > 0) {
            if (s[i] == 'A')
                x -= 1;
            else
                x /= 2;
            ans++;
            if (i++ == n) i = 0;
        }
        cout << ans << endl;
    }
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