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
    int n, k;
    cin >> n >> k;
    vint l(n), r(n);
    for (auto &&i : l) {
        cin >> i;
    }
    for (auto &&i : r) {
        cin >> i;
    }
    vpii sumk(n);
    for (size_t i = 0; i < n; i++) {
        sumk[i].first = l[i] + r[i];
        sumk[i].second = i;
    }
    ranges::stable_sort(sumk, [&](auto a, auto b) { return a.first > b.first; });
    int ans = 0;
    set<int> used;
    for (size_t i = 0; i < k - 1; i++) {
        ans += sumk[i].first;
        used.insert(sumk[i].second);
    }
    for (size_t i = 0; i < n; i++) {
        if (used.contains(i)) continue;
        ans += max(l[i], r[i]);
    }
    cout << ans + 1 << endl;
}

void solve2()
{
    int n, k;
    cin >> n >> k;
    vint l(n), r(n);
    for (auto &&i : l) {
        cin >> i;
    }
    for (auto &&i : r) {
        cin >> i;
    }
    vint pass(n);
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
        pass[i] = min(l[i], r[i]);
    }
    ranges::sort(pass, greater<int>{});
    for (size_t i = 0; i < k - 1; i++) {
        ans += pass[i];
    }
    cout << ans + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve2();
    }
    return 0;
}