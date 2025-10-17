//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define endl '\n'
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
    i64 n;
    cin >> n;
    cout << "2 " << 1 << " " << n << endl;
    i64 res = 0;
    cin >> res;
    i64 sum = ((n) * (n + 1)) / 2;
    i64 len = res - sum;
    i64 l = 1, r = n;
    i64 get = 0;
    i64 cur = 0;
    // cout << len << endl;
    while (l < r) {
        i64 mid = (l + r) >> 1;
        i64 lenk = (r - l + 1);

        cout << "1 " << 1 << " " << mid << endl;
        i64 res1;
        cin >> res1;
        cout << "2 " << 1 << " " << mid << endl;
        i64 res2;
        cin >> res2;
        i64 k1 = res2 - res1;
        if (k1 > 0 && k1 < len) {
            i64 L = mid - k1 + 1;
            i64 R = L + (len - 1);
            cout << "! " << L << " " << R << endl;
            return;
        }
        if (k1 == len) {
            r = mid;
        }
        if (k1 == 0) {
            l = mid + 1;
        }
    }
    i64 R = l;
    i64 L = R - len + 1;
    cout << "! " << L << " " << R << endl;
}
signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}