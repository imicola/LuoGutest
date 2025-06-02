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

static int MOD = 998244353;

long long ksm(long long a, long long b, long long MOD)
{
    long long ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vint p(n), q(n);
    for (auto &&i : p) cin >> i;
    for (auto &&i : q) cin >> i;
    // 预处理 2^i 模 MOD
    vint pw = {1};
    if ((int)pw.size() < n + 1) {
        int old = pw.size();
        pw.resize(n + 1);
        for (int i = old; i <= n; i++) pw[i] = pw[i - 1] * 2 % MOD;
    }
    int A = -1, B = -1;
    int j0 = 0, k0 = 0;
    vint r(n);
    for (int i = 0; i < n; i++) {
        if (p[i] > A) {
            A = p[i];
            j0 = i;
        }
        if (q[i] > B) {
            B = q[i];
            k0 = i;
        }
        int x = 0, y = 0;
        if (A > B) {
            x = A;
            y = q[i - j0];
        }
        else if (B > A) {
            x = B;
            y = p[i - k0];
        }
        else {
            x = A;
            y = max(q[i - j0], p[i - k0]);
        }
        r[i] = (pw[x] + pw[y]) % MOD;
    }
    for (auto &&i : r) {
        cout << i << " ";
    }
    cout << endl;
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