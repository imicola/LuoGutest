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

constexpr const i64 MOD = 998244353;

void solve()
{
    i64 n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vint preA(n + 1, 0);
    vint preM(n + 1, 0);
    vint pres1(n + 1, 0);
    vint pres2(n + 1, 0);
    vint preC(n + 1, 0);
    vint pres3(n + 1, 0);
    // ACM对于每个C_k，都为 f(c) = (preA[k - 1] - preA[l - 1])*(preM[r] - preM[k + 1])
    for (i64 i = 1; i <= n; i++) {
        preA[i] = preA[i - 1] + (s[i - 1] == 'A' ? 1 : 0) % MOD;
        preM[i] = preM[i - 1] + (s[i - 1] == 'M' ? 1 : 0) % MOD;
        preC[i] = preC[i - 1];
        pres1[i] = pres1[i - 1];
        pres2[i] = pres2[i - 1];
        pres3[i] = pres3[i - 1];
        if (s[i - 1] == 'C') {
            preC[i] = (preC[i] + 1) % MOD;
            pres1[i] = (pres1[i] + ((preA[i - 1] * preM[i]) % MOD)) % MOD;
            pres2[i] = (pres2[i] + preA[i - 1]) % MOD;
            pres3[i] = (pres3[i] + preM[i]) % MOD;
        }
    }
    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 prea = preA[l - 1];
        i64 prem = preM[r];
        i64 k1 = (prem * (pres2[r] - pres2[l - 1] + MOD) % MOD) % MOD;
        i64 k2 = (pres1[r] - pres1[l - 1] + MOD) % MOD;
        i64 k3 = (prea * (pres3[r] - pres3[l - 1] + MOD) % MOD);
        i64 k4 = ((prea * prem % MOD) * (preC[r] - preC[l - 1] + MOD) % MOD) % MOD;
        cout << ((k1 - k2 + MOD) % MOD + (k3 - k4 + MOD) % MOD) % MOD << endl;
    }
}

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