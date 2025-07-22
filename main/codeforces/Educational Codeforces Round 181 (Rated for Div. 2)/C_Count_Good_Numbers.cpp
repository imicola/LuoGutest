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

vint prime = {2, 3, 5, 7};

int f(int n)
{
    int cnt = 0;
    for (size_t mask = 1; mask < (1 << 4); mask++) {
        int k = 1, bits = 0;
        for (size_t i = 0; i < 4; i++) {
            if ((mask >> i) & 1) {
                if ((n / prime[i]) < k) {
                    k = n + 1;
                    break;
                }
                k *= prime[i];
                bits++;
            }
        }
        if (k > n) continue;
        if (bits % 2)
            cnt += n / k;
        else
            cnt -= n / k;
    }
    return cnt;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << (r - l + 1) - f(r) + f(l - 1) << endl;
}
// 2357 = 2 + 3 + 5 + 7 - 23 - 25 - 27 - 35 - 37 - 57 + 235 + 257 + 237 + 357 - 2357
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