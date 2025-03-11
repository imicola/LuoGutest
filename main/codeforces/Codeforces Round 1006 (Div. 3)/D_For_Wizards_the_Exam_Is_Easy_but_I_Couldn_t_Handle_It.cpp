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
    vint a(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxx = 0;
    pii res = make_pair(1, 1);
    auto [l, r] = res;
    for (size_t i = 1; i < n; i++) {
        int cnt = 0;
        for (size_t j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                cnt++;
            }
            else if (a[j] > a[i]) {
                cnt--;
            }
            if (cnt > maxx) {
                maxx = cnt;
                l = i;
                r = j;
            }
        }
    }
    cout << l << " " << r << endl;
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