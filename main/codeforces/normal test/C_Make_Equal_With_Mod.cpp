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
    set<int> st;
    for (size_t i = 0; i < n; i++) {
        int t;
        cin >> t;
        st.insert(t);
    }
    if (st.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    if (st.contains(1) && st.contains(2) || st.contains(0) && st.contains(1)) {
        cout << "NO" << endl;
        return;
    }
    vint v(all(st));
    int diff = INT_MAX;
    for (size_t i = 0; i + 1 < v.size(); i++) {
        diff = min(diff, v[i + 1] - v[i]);
    }
    cout << (st.contains(1) && diff <= 1 ? "NO" : "YES") << endl;
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