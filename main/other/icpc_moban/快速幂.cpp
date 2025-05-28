#include <bits/stdc++.h>
using namespace std;

long long ksm(long long a, long long b)
{
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

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
// 乘法逆元
long long nksm(long long a, long long MOD)
{
    return ksm(a, MOD - 2, MOD);
}

int main()
{
    cout << nksm(2, 7);
}