#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'
using namespace std;
typedef vector<int> vint;
const int MOD = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vint a(n), b(n);
    for (auto &&i : a) cin >> i;
    for (auto &&i : b) cin >> i;
    int fidx1 = 0, fidx2 = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(a[i] == b[fidx1] && fidx1 < n){
            fidx1++;
            continue;
        }
        if(a[i] == b[fidx2] && fidx2 != fidx1){
            fidx2++;
        }
    }
    cout << (fidx1 == m && fidx2 >= m ? "Yes" : "No") << endl;
}

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