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
    int n, m;
    cin >> n >> m;
    vint b(n + 1, 0);
    auto add = [&](int i, int k) {
        while (i <= n) {
            b[i] += k;
            i += i & (-i);
        }
    };
    auto sum = [&](int i) -> int {
        int cnt = 0;
        while (i > 0) {
            cnt += b[i];
            i -= i & (-i);
        }
        return cnt;
    };
    auto rsum = [&](int l, int r) { return sum(r) - sum(l - 1); };
    for (size_t i = 1; i <= n; i++) {
        int p;
        cin >> p;
        add(i, p);
    }
    while (m--) {
        int s;
        cin >> s;
        if (s == 1) {
            int x, k;
            cin >> x >> k;
            add(x, k);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << rsum(l, r) << endl;
        }
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