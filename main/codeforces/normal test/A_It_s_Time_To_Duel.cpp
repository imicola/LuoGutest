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
    vint v(n);
    unordered_set<int> st;
    for (auto &&i : v) {
        cin >> i;
        st.insert(i);
    }
    if (st.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    int d0 = 0;
    for (size_t i = 0; i + 1 < n; i++) {
        if (v[i] == v[i + 1] && v[i] == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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