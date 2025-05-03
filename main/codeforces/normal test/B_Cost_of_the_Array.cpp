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
    int n, k;
    cin >> n >> k;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    if (v[1] != 1) {
        cout << 1 << endl;
        return;
    }
    if (n == k) {
        int now = 1;
        for (size_t i = 0; i < n; i++) {
            if ((i + 1) % 2 == 1) continue;
            if (v[i] != now) {
                cout << now << endl;
                return;
            }
            now++;
        }
        cout << now << endl;
        return;
    }
    v[0] = 1;
    int p = (n - k + 1);
    for (size_t i = 0; i < n; i++) {
        int cnt = 0;
        while (i < n && v[i] == 1) {
            i++;
            cnt++;
        }
        if (cnt >= p + 1) {
            cout << 2 << endl;
            return;
        }
        else {
            cout << 1 << endl;
            return;
        }
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