#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 ksm(i64 a, i64 b)
{
    i64 ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

i64 ksm(i64 a, i64 b, i64 MOD)
{
    i64 ans = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
// 乘法逆元
long long nksm(long long a, long long MOD)
{
    return ksm(a, MOD - 2, MOD);
}

int main()
{
    cout << nksm(2, 7);
}