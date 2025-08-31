#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v, begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

void solve()
{
    int n, q;
    cin >> n >> q;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    while (q--) {
        int op, i, x;
        cin >> op >> i >> x;
        if (op == 1) v[i - 1] += x;
        if (op == 2) v[i - 1] -= x;
    }
    for (auto &&i : v) {
        cout << i << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}