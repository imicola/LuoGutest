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
    int n, k;
    cin >> n >> k;
    vint v(n);
    int minn = INT_MAX;
    for (auto &&i : v) {
        cin >> i;
        minn = min(minn, i);
    }
    if (minn != 0) {
        cout << 0 << endl;
        return;
    }
    int p = n - k + 1;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
    }
    
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