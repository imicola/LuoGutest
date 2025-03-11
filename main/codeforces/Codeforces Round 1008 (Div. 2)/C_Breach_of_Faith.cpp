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
    vint a(2 * n + 1);
    int maxx = 0;
    for (size_t i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int maxx_p = 0;
    int idx = 0;
    int sumx = 0;
    for (size_t i = 1; i <= 2 * n; i += 2) {
        if (a[i] == maxx || a[i + 1] == maxx) {
            maxx_p = (a[i] == maxx ? a[i + 1] : a[i]);
            idx = i;
            continue;
        }
        if (a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            sumx += a[i] - a[i + 1];
        }
        else {
            sumx += a[i] - a[i + 1];
        }
    }
    int p = maxx_p - sumx + maxx;
    // maxx = p - maxx_p + sumx;
    cout << maxx << " " << p << " " << maxx_p << " ";
    for (size_t i = 1; i <= 2 * n; i++) {
        if (i == idx || i == idx + 1) {
            continue;
        }
        cout << a[i] << " ";
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