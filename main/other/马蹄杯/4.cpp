#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'
using namespace std;
typedef vector<int> vint;
const int MOD = 998244353;

int ksm(int a, int base)
{
    int res = 1;
    while (base > 0) {
        if (base & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        base >>= 1;
    }
    return res;
}

int C(int p, int q)
{
    int res1 = 1, res2 = 1;
    for (size_t i = 0; i < p; i++) {
        res1 = (res1 * (q - i)) % MOD;
    }
    for (size_t i = 1; i <= p; i++) {
        res2 = (res2 * i) % MOD;
    }
    int res = ((res1) / (res2)) % MOD;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0 << endl;
        return;
    }
    cout << (((ksm(26, n - 3) % MOD * C(3, n) % MOD) % MOD) * 6) % MOD << endl;
}

void solvec(){
    int n;
    cin >> n;
    int k26 = ksm(26, n);
    int k25 = ksm(25, n);
    int k24 = ksm(24, n);
    int k23 = ksm(23, n);
    int ans = (k26 - 3 * k25 % MOD + 3 * k24 % MOD - k23 + MOD) % MOD;
    cout << ans;
}

// s = ksm(26,n-3)*C(3,n)*6

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}