#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'
using namespace std;
typedef vector<int> vint;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vint a(n + 1, 0), b(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (size_t i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vint apsum(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        apsum[i] = apsum[i - 1] + a[i];
    }
    
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