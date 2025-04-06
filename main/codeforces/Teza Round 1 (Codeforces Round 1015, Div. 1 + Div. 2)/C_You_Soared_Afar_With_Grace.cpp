//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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
    map<int, int> a1, a2, b1, b2;
    for (size_t i = 1; i <= n; i++) {
        int temp = 0;
        cin >> temp;
        a1[i] = temp;
        a2[temp] = i;
    }
    for (size_t i = 1; i <= n; i++) {
        int temp = 0;
        cin >> temp;
        b1[i] = temp;
        b2[temp] = i;
    }
    if (a1 == b1) {
        cout << -1 << endl;
        return;
    }
    for (auto &&[i, j] : a1) {
        // cout << a1[b2[j]] << " " << b1[i] << endl;
        if (a1[b2[j]] != b1[i]) {
            cout << -1 << endl;
            return;
        }
    }
    vpii res;
    for (auto &&[i, j] : a1) {
        // cout << b2[j] << " " << i << " " << j << endl;
        if (n + 1 - b2[j] != i) {
            res.emplace_back(i, n + 1 - b2[j]);
            a2[j] = n + 1 - b2[j];
            a2[n + 1 - b2[j]] = i;
            b2[n + 1 - b2[j]] = i;
            b2[j] = n + 1 - b2[j];
            swap(a1[i], a1[n + 1 - b2[j]]);
            swap(b1[i], b1[n + 1 - b2[j]]);
        }
    }
    cout << res.size() << endl;
    for (auto &&[a, b] : res) {
        cout << a << " " << b << endl;
    }
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