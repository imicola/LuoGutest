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
    vint v(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    ranges::sort(v);
    if ((v.front() + v.back()) % 2 == 0) {
        cout << 0 << endl;
        return;
    }
    int i = 0, j = n - 1;
    int p1 = v[i] % 2;
    int cnt1 = 0, cnt2 = 0;
    while ((v[i] % 2) == p1) {
        i++;
        cnt1++;
        // cout << "p" << " ";
    }
    // cout << v[j] << " " << p1;
    while ((v[j] % 2) != p1) {
        j--;
        cnt2++;
    }
    cout << min(cnt1, cnt2) << endl;
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