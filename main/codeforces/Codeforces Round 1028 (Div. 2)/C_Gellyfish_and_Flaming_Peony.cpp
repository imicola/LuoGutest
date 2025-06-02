#pragma GCC optimize("O3")
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
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    int g = v[0];
    for (auto &&x : v) {
        g = __gcd(g, x);
    }
    int cnt = 0;
    for (int x : v)
        if (x == g) cnt++;
    if (cnt > 0) {
        cout << (n - cnt) << '\n';
        return;
    }
    const int A = 5000;
    vint dist(A + 1, INT_MAX);
    queue<int> q;
    for (int x : v) {
        if (dist[x] > 0) {
            dist[x] = 0;
            q.push(x);
        }
    }
    int d = -1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == g) {
            d = dist[x];
            break;
        }
        for (int y : v) {
            int nx = gcd(x, y);
            if (dist[nx] > dist[x] + 1) {
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
    cout << (d + n - 1) << '\n';
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