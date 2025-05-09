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
    set<int> st;
    for (auto &&i : v) {
        cin >> i;
        st.insert(i);
    }
    if (st.size() == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int idx = ranges::max_element(v) - v.begin();
    for (size_t i = 0; i < idx; i++) {
        cout << 1 << " ";
    }
    cout << 2 << " ";
    for (size_t i = idx + 1; i < n; i++) {
        cout << 1 << " ";
    }
    cout << endl;
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