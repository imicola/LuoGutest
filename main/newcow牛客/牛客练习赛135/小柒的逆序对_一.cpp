#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vint a(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int p = m % 2;
    for (size_t i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        if(t-k != 0){
            p ^= 1;
        }
        cout << (p ? "odd" : "even") << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}