//#pragma GCC optimize(3)
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
    int n;
    cin >> n;
    if(n == 3){
        cout << 1;
        return;
    }
    int p = 0;
    while (p * p <= 2*n) {
        p++;
    }
    int ans = 0;
    int k = 100;
    for (size_t i = 2; i <= p && i * i <= n; i++) {
        if ((i * i) % 2 == 0)
            ans += ((i * i) / 2) - 1;
        else
            ans += ((i * i) / 2);
        k = i;
    }
    k++;
    for (; k < p; k++) {
        ans += n - (((k * k) / 2));
    }
    cout << ans;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}