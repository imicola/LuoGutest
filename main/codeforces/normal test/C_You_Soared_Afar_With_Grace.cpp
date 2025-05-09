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
    map<int, int> a_pos;
    vint a(n + 1, 0), b(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        int t;
        cin >> t;
        a_pos[t] = i;
        a[i] = t;
    }
    for (size_t i = 1; i <= n; i++) {
        int t;
        cin >> t;
        b[i] = t;
    }
    int x = 0;
    for (size_t i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (n % 2 == 0 || x) {
                cout << -1 << endl;
                return;
            }
            x = i;
        }
        else if (b[a_pos[b[i]]] != a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    vpii res;
    auto swapp = [&](int i, int idx) {
        if (i == idx) return;
        a_pos[a[i]] = idx;
        a_pos[a[idx]] = i;
        swap(a[i], a[idx]);
        swap(b[i], b[idx]);
        res.emplace_back(i, idx);
    };
    if (n % 2) {
        int idx = (n + 1) / 2;
        swapp(x, idx);
    }
    for (int i = 1; i <= n / 2; i++) {
        swapp(a_pos[b[i]], n - i + 1);
    }
    cout << res.size() << endl;
    for (auto &&[i, j] : res) {
        cout << i << " " << j << endl;
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