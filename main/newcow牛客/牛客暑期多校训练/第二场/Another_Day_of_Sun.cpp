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

constexpr int MOD = 998244353;

int ksm(int base, int exp)
{
    int ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vint a(n + 1);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) k++;
    }
    int ans = 0;
    if (a[1] == 1) {
        ans = (ans + ksm(2, k)) % MOD;
    }
    else if (a[1] == -1) {
        ans = (ans + ksm(2, k-1)) % MOD;
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0 || a[i - 1] == 1) continue;
        int req = 0;
        if (a[i] == -1) req++;
        if (a[i - 1] == -1) req++;
        ans = (ans + ksm(2, k - req)) % MOD;
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