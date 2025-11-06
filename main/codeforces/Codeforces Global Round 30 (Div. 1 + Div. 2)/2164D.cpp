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
    int n, kmax;

    cin >> n >> kmax;

    string s, t;

    cin >> s >> t;

    vector<vector<int>> pos(26);

    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    auto check = [&](int k, vector<int> &pp) -> bool {
        pp = vector<int>(n, -1);
        int prev = 0;

        for (int i = 0; i < n; i++) {
            int c = t[i] - 'a';
            auto &v = pos[c];

            if (v.empty()) {
                return 0;
            }

            int need = max(prev, i - k);
            auto it = lower_bound(v.begin(), v.end(), need);

            if (it == v.end() or *it > i) {
                return 0;
            }

            pp[i] = *it;
            prev = pp[i];
        }

        return 1;
    };

    int l = 0, r = n;
    int ans = -1;
    vector<int> vv;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(mid, vv)) {
            r = (ans = mid) - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (ans == -1 or ans > kmax) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
    if (ans == 0) {
        return;
    }
    vector<int> anss;
    check(ans, anss);
    string cur = s;

    for (int tmp = 1; tmp <= ans; tmp++) {
        string nxt = cur;

        for (int i = 1; i < n; i++) {
            if (i - anss[i] >= tmp) {
                nxt[i] = cur[i - 1];
            }
            else {
                nxt[i] = cur[i];
            }
        }
        cout << nxt << endl;
        cur.swap(nxt);
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