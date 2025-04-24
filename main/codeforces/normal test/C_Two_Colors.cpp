// #pragma GCC optimize(3)
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


// TODO:写题解

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (a > n) a = n;
        v[a]++;
    }
    vector<int> rsum(n + 2, 0);
    rsum[n] = v[n];
    for (int k = n - 1; k >= 1; k--) {
        rsum[k] = rsum[k + 1] + v[k];
    }
    int ans = 0;
    for (int k = 1; k <= n - 1; k++) {
        int Ck = rsum[k];
        int Cnk = rsum[n - k];
        int Cmax = rsum[max(k, n - k)];
        ans += Ck * Cnk - Cmax;
    }
    cout << ans << endl;
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