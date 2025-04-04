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

int n;
vint v, v2;

int f(int k1, int i)
{
    if (v[k1] == i) {
        return 0;
    }
    if (v[k1] == 0) {
        return 1;
    }
    if (v[k1] != k1) {
        return f(v[k1], i) + 1;
    }
    return 0;
}

void solve()
{
    cin >> n;
    vint v2 = vint(n + 1, 0);
    vint v1 = vint(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (size_t i = 1; i <= n; i++) {
        cin >> v2[i];
    }
    for (size_t i = 1; i <= n; i++) {
        v[v2[i]] = 0;
        cout << f(v[v2[i]], i) << " ";
    }
    cout << endl;
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