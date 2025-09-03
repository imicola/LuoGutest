//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const i64 MOD = 998244353;

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

struct Stirling
{
    vector<i64> fac, inv_fac;
    i64 MAX_N;
    Stirling(i64 MAXK)
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
    i64 C(i64 n, i64 k)
    {
        if (k < 0 || k > n) return 0;
        if (n < MOD && k < MOD) return C_small(n, k);
        return C(n / MOD, k / MOD) * C_small(n % MOD, k % MOD) % MOD;
    }
    i64 A(int n, int k) const
    {
        if (k < 0 || k > n) return 0;
        return fac[n] * inv_fac[n - k];
    }
    // 第二类斯特林数的显式表示
    i64 get_Stirling(int n, int k)
    {
        if (k < 0 || k > n) return 0;
        i64 res = 0;
        for (int i = 0; i <= k; ++i) {
            i64 term = C(k, i) * ksm(k - i, n) % MOD;
            // 符号： (-1)^i，根据公式 S(n,k) = 1/k! * sum_{i=0..k} (-1)^i C(k,i) (k-i)^n
            if (i & 1)
                res = (res - term + MOD) % MOD;
            else
                res = (res + term) % MOD;
        }
        res = res * inv_fac[k] % MOD; // 除以 k!
        return res;
    }
    // 第二类欧拉数计算
    i64 sec_Eulr(int n, int k)
    {
        return (get_Stirling(n, k) * fac[k]) % MOD;
    }
};

void solve()
{
    i64 n, m;
    cin >> n >> m;
    Stirling a(5000);
    cout << a.sec_Eulr(n, m);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}