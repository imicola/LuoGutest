// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18

void solve()
{
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    int idx = n - 1;
    int maxk = 0;
    vector<int> vis(n);
    for (int i = n - 1; i >= 0; i--) {
        // 遍历s2
        auto cur = s2[i];
        while (idx > i) {
            idx--;
        }
        while (idx >= 0 and s1[idx] != cur) {
            idx--;
        }
        if (s1[idx] != cur or idx == -1) {
            return void(cout << -1 << endl);
        }
        // cout << idx << ' ' << s1[idx] << ' ' << i << ' ' << cur << endl;
        maxk = max(maxk, i - idx);

        vis[idx] = max(vis[idx], i);
    }

    if (maxk > k) {
        return void(cout << -1 << endl);
    }

    cout << maxk << endl;
    for (int i = 0; i < n; i++) {
        // cout << vis[i] << ' ';
    }
    for (int _ = 0; _ < maxk; _++) {
        vector<char> tmp(n);
        for (int i = n - 1; i >= 0; i--) {
            if (vis[i]) {
                tmp[i] = s1[i];
            }
            if (i - 1 >= 0 and vis[i - 1] >= i) {
                tmp[i] = s1[i - 1];
                vis[i] = vis[i - 1];
            }
            else {
                tmp[i] = s1[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << tmp[i];
            s1[i] = tmp[i];
        }
        cout << endl;
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
        // cout << endl;
    }
}