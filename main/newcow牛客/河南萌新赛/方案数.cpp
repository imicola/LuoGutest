//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

static constexpr i64 MOD = 1e9 + 7;

i64 ksm(const i64 &a, i64 b, i64 mod = MOD)
{
    i64 res = 1;
    i64 p = a % mod;
    while (b) {
        if (b & 1) res = res * p % mod;
        b >>= 1;
        p = p * p % mod;
    }
    return res;
}

struct Comb
{
    vector<i64> fac, inv_fac;
    i64 MAX_N;
    Comb(i64 MAXK)
    {
        MAX_N = MAXK;
        fac.resize(MAX_N);
        inv_fac.resize(MAX_N);
        init();
    }
    // 预处理 [0, MOD-1] 阶乘及逆元
    void init()
    {
        fac[0] = 1;
        for (i64 i = 1; i < MAX_N; i++) fac[i] = fac[i - 1] * i % MOD;
        inv_fac[MAX_N - 1] = ksm(fac[MAX_N - 1], MOD - 2);
        for (i64 i = MAX_N - 2; i >= 0; i--) inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
    // 计算 C(n, k) mod MOD，要求 n, k < MOD
    inline i64 C_small(i64 n, i64 k)
    {
        if (k < 0 || k > n) return 0;
        return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
    }
    // Lucas 定理递归求解大组合数
    inline i64 C(i64 n, i64 k)
    {
        if (k < 0 || k > n) return 0;
        if (n < MOD && k < MOD) return C_small(n, k);
        return C(n / MOD, k / MOD) * C_small(n % MOD, k % MOD) % MOD;
    }
    inline i64 A(int n, int k) const
    {
        if (k < 0 || k > n) return 0;
        return fac[n] * inv_fac[n - k];
    }
};

void solve()
{
    i64 n, k, m;
    cin >> n >> k >> m;
    Comb x(1000 + 10);
    cout << (x.C(n, k) * ksm(m, k)) % MOD;
}
// C(n,k)m^k
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}