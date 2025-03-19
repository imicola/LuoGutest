//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
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
    vpii ranted1;
    vpii ranted2;
    for (size_t i = 1; i <= n; i++) {
        int k;
        cin >> k;
        ranted1.emplace_back(k, i);
    }
    for (size_t i = 1; i <= n; i++) {
        int k;
        cin >> k;
        ranted2.emplace_back(i, k);
    }
    ranges::stable_sort(ranted2, [](pii a, pii b) { return a.second < b.second; });
    ranges::stable_sort(ranted1, [](pii a, pii b) { return a.second > b.second; });
    for (size_t i = 0; i < ranted2.size(); i++) {
        ranted2[i].second = i + 1;
    }
    for (size_t i = 0; i < ranted1.size(); i++) {
        ranted1[i].second = i + 1;
    }
    ranges::stable_sort(ranted2, [](pii a, pii b) { return a.first < b.first; });
    ranges::stable_sort(ranted1, [](pii a, pii b) { return a.first < b.first; });
    vpii ans(n);
    for (size_t i = 0; i < n; i++) {
        ans[i].first = i + 1;
        ans[i].second = ranted2[i].second + ranted1[i].second;
    }
    ranges::stable_sort(ans, [&](pii a, pii b) {
        if (a.second == b.second) {
            int i1 = a.first;
            int i2 = b.first;
            int k1, k2;
            for (auto &&[x, y] : ranted2) {
                if (x == i1) k1 = y;
                if (x == i2) k2 = y;
            }
            return k1 > k2;
        }
        return a.second > b.second;
    });
    for (int p = 0; auto &&[a, b] : ans) {
        printf("%d. Kod%02d (%d)\n", ++p, a, b);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}