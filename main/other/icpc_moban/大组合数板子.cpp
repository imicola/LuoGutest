//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
i64 MOD = 998244353;

// 快速幂
i64 ksm(i64 a, i64 b, i64 mod = MOD)
{
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
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
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    Comb a(10000);

    return 0;
}