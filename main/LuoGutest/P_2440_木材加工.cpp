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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, k;
    cin >> n >> k;
    vint v(n);
    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 0, r = 1e8;
    int res = 0;
    while (l + 1 < r) {
        int mid = (l + r + 1) / 2;
        int cnt = 0;
        for (auto &&i : v) {
            cnt += i / mid;
        }
        if (cnt < k) {
            r = mid;
        }
        else if (cnt >= k) {
            l = mid;
        }
        if (l == 0 && r == 1) {
            cout << 0;
            return 0;
        }
        // cout << l << " " << r << " " << cnt << endl;
    }
    cout << l;
    return 0;
}