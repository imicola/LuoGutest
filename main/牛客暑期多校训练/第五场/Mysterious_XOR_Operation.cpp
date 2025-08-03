//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void solve() {
    int n;
    cin >> n;
    vint a(n);
    for (auto &&i : a) cin >> i;
    int sum = 0;
    for (int k = 0; k < 30; k++) {
        int cnt[2][2] = {{0, 0}, {0, 0}};
        int mask = (k == 0) ? 0 : (1 << k) - 1;
        for (auto && i : a) {
            int bit = (i >> k) & 1;
            int low = i & mask;
            int parity = __builtin_popcount(low) % 2;
            cnt[bit][parity]++;
        }
        int p0 = cnt[0][0] * cnt[1][0];
        int p1 = cnt[0][1] * cnt[1][1];
        int total = p0 + p1;
        sum += total * (1LL << k);
    }
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}
