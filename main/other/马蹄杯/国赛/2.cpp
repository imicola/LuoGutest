#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(v) v, begin(), v.end()
using namespace std;
typedef vector<int> vint;
typedef vector<pair<int, int>> vpii;

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> a;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.insert(temp);
    }
    if (a.size() < k) {
        cout << -1 << endl;
        return;
    }
    auto it = a.begin();
    advance(it, k - 1);
    cout << *it << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}