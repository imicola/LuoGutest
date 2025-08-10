#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pii(n);
    for (auto &&[l, r] : pii) {
        cin >> l >> r;
    }
    sort(all(pii), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    int ans = 0;
    ans += (pii[0].second - pii[0].first + 1);
    int kl = pii[0].first, kr = pii[0].second;
    for (size_t i = 1; i < pii.size(); i++) {
        auto &&[l, r] = pii[i];
        if (r < kr)
            continue;
        else {
            if (l > kr) {
                ans += r - l + 1;
            }
            else {
                ans += max(0ll, (r - l + 1 - (kr - l + 1)));
            }
            kr = r;
        }
    }
    cout << ans << endl;
}

// l1 0  l2 0 0 0 0 0 0 r2 l3 r1

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