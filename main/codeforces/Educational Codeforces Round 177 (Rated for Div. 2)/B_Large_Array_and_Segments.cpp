//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
#define size_t int
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
    int n, k, x;
    cin >> n >> k >> x;
    vint v(n);
    int sum = 0;
    for (auto &&i : v) {
        cin >> i;
        sum += i;
    }
    vint rsum(n + 1);
    rsum[n] = 0;
    rsum[n - 1] = v.back();
    for (int i = n - 2; i >= 0; i--) {
        rsum[i] = v[i] + rsum[i + 1];
    }
    int p = x / sum;
    int t = p * sum;
    // cout << p << endl;
    if (p == 0) {
        for (size_t i = 0; i <= n; i++) {
            if (rsum[i] < x) {
                cout << n * (k - 1) + i << endl;
                return;
            }
        }
    }
    else {
        int q = sum * p;
        if (x > k * sum) {
            cout << 0 << endl;
            return;
        }
        for (size_t i = 0; i <= n; i++) {
            if (rsum[i] + q < x) {
                cout << (n * (k - p - 1) + i) << endl;
                return;
            }
        }
        cout << n * (k - p) + 1 << endl;
    }

    // cout << endl;
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