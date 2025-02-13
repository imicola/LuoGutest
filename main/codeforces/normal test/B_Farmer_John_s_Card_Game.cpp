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
    int n, m;
    cin >> n >> m;
    map<int, int> p;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            int temp;
            cin >> temp;
            p[temp] = i;
        }
    }
    vint check(n * m);
    vint ch2(n);
    int c = 0;
    for (auto &&[v, index] : p) {
        check[c] = index;
        c++;
    }
    for (size_t i = 0; i < n * m; i++) {
        // cout << "test:" << check[i] << " " << ch2[i % n] << " ";
        if (i < n) {
            ch2[i] = check[i];
        }
        else {
            if (check[i] != ch2[i % n]) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto &&i : ch2) {
        cout << i << " ";
    }

    cout << endl;
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