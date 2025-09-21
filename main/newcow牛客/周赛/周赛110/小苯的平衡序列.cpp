//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    vint v(n);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(all(v));
    i64 len = v.size();
    i64 lmid = v[len / 2 - 1];
    i64 rmid = v[len / 2];
    i64 mid = 0;
    // cout << lmid << " " << rmid << endl;
    auto f = [&](i64 x) -> i64 {
        i64 res = 0;
        for (i64 i = 0; i < n; i++) {
            if (i == x) continue;
            res += abs(v[i] - mid);
        }
        return res;
    };
    i64 ans1 = 0, ans2 = 0;
    mid = rmid;
    ans1 = f(0);
    mid = lmid;
    ans2 = f(len - 1);

    cout << min(ans1, ans2) << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}