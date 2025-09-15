#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int maxx = INT_MIN;
    for (auto &&i : v) {
        cin >> i;
        maxx = max(maxx, i);
    }
    vector<int> ext;
    int ans = 0;
    set<int, greater<int>> st;
    for (size_t i = 0; i < n; i++) {
        if (!st.contains(v[i])) st.insert(v[i]);
        auto it = st.find(v[i]);
        int dis = distance(st.begin(), it);
        ans += dis;
    }
    set<int, greater<int>> st2;
    for (int i = n - 1; i >= 0; i--) {
        if (!st2.contains(v[i])) st2.insert(v[i]);
        auto it = st2.find(v[i]);
        int dis = distance(st2.begin(), it);
        ans += dis;
    }
    cout << ans << endl;
}
// 1 2 2 4 5
// 0 1 0 2 1
//
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}