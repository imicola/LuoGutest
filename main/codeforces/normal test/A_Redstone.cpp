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

void solve()
{
    int n;
    cin >> n;
    vint a(n);
    set<int> st;
    bool g = 0;
    for (auto &&i : a) {
        cin >> i;
        if (st.contains(i)) g = 1;
        st.insert(i);
    }
    cout << (g != 1 ? "NO" : "YES") << endl;
}
// x y z
// z_back = 1
// z_i = x_i/x_(i-1)*z_(i - 1)
// z_i/z_(i - 1) = x_i/x_i-1
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}