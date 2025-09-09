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
    vector<set<int>> vst(n);
    for (size_t i = 0; i < n; i++) {
        if (i) vst[i] = vst[i - 1];
        int dis = 0;
        while (!vst[i].empty() && (*vst[i].begin()) <= v[i]) {
            vst[i].erase(vst[i].begin());
        }
        dis += vst[i].size();
        vst[i].insert(v[i]);
        ans += dis;
    }
    // cout << ans << " ";
    vector<set<int>> vst2(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) vst2[i] = vst2[i + 1];
        int dis = 0;
        while (!vst2[i].empty() && (*vst2[i].begin()) <= v[i] || vst[i].contains(*vst2[i].begin())) {
            vst2[i].erase(vst2[i].begin());
        }
        dis += vst2[i].size();
        vst2[i].insert(v[i]);
        ans += dis;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}