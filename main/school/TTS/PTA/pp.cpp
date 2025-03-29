#pragma GCC optimize(3)
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
    int n;
    while (cin >> n) {
        vint v(n);
        for (auto &&i : v) {
            cin >> i;
        }
        vint psum(n + 1, 0);
        for (size_t i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + v[i - 1];
        }
        int q;
        cin >> q;
        for (size_t i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--, r--; // pos ->index
            int mid = (r + l) / 2;
            int l2 = mid - l + 1;
            int r2 = r - mid;
            int left = psum[mid + 1] - psum[l];
            int right = psum[r + 1] - psum[mid + 1];
            int ans = (v[mid] * l2 - left) + (right - v[mid] * r2);
            cout << ans << endl;
        }
    }
}

// 012345
// 101101

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}