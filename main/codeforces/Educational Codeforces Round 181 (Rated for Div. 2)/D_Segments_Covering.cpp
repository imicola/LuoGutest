//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// 逆元下快速幂
static const int MOD = 998244353;
long long nksm(long long a, long long e = MOD - 2)
{
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vpii> ends(m + 1);
    int B = 1;
    for (int i = 0; i < n; i++) {
        int l, r;
        int p, q;
        cin >> l >> r >> p >> q;
        // 1 - p/q = (q-p)/q
        int invq = nksm(q);
        int prob_off = (q - p) % MOD * invq % MOD;
        B = B * prob_off % MOD;
        // w = (p/q) / (1 - p/q) = p/(q-p)
        int w = p % MOD * nksm((q - p + MOD) % MOD) % MOD;
        ends[r].emplace_back(l, w);
    }
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int x = 1; x <= m; x++) {
        int sum = 0;
        for (auto &pr : ends[x]) {
            int l = pr.first;
            int w = pr.second;
            sum = (sum + w * dp[l - 1]) % MOD;
        }
        dp[x] = sum;
    }
    int ans = B * dp[m] % MOD;
    cout << ans << endl;
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
