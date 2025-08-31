#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v, begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

void solve()
{
    int n, m;
    cin >> n >> m;
    vint a(n);
    int sum = 0;
    for (auto &&i : a) {
        cin >> i;
        sum += i;
    }
    if (sum <= m) {
        cout << 1 << endl;
        return;
    }
    int l = 1, r = 1e9;
    auto get_sum = [&](int D) -> int {
        int res = 0;
        for (auto &&i : a) {
            res += i / D;
        }
        return res;
    };
    // D越大get越小，需要D的最小值
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (get_sum(mid) <= m) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << endl;
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