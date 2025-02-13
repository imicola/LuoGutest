//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <ranges>
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
    int n, m;
    cin >> n >> m;
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    int b;
    cin >> b;
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    a[0] = min(a[0], b - a[0]);
    a[n - 1] = max(a[n - 1], b - a[n - 1]);
    for (size_t i = 1; i < n - 1; i++) {
        if (a[i] >= a[i - 1]) {
            if (b - a[i] >= a[i - 1]) {
                a[i] = min(b - a[i], a[i]);
            }
        }
        else {
            if (b - a[i] >= a[i - 1]) {
                a[i] = b - a[i];
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}