//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint v(n + 1);
    set<i64> st;
    for (i64 i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        st.erase(v[i]);
    }
    vint res(3);
    if (st.empty()) {
        res[0] = v[1];
        res[1] = v[2];
        res[2] = v[3];
    }
    else {
        res[0] = *st.begin();
        res[2] = v[n];
        i64 ok = 0;
        for (auto &&i : st) {
            if (i != res[0] && i != res[2]) {
                res[1] = i;
                ok = 1;
            }
        }
        for (i64 i = 1; i <= n && !ok; i++) {
            if (v[i] != res[0] && v[i] != res[2]) {
                res[1] = v[i];
                break;
            }
        }
    }
    for (i64 i = 0; i < k; i++) {
        cout << res[i % 3] << " ";
    }
    cout << endl;
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