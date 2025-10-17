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
    vint res(n + 1);
    set<i64> st;
    for (i64 i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
        res[n - i + 1] = v[i];
        st.erase(v[i]);
    }
    if (st.size() >= k) {
        vint ans(all(st));
        for (i64 i = 0; i < k; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    else {
        vint ans(all(st));
        for (auto &&i : ans) {
            cout << i << " ";
        }
        i64 len = ans.size();
        i64 cnt = 1;
        for (i64 i = len + 1; i <= k; i++) {
            if (v[i] == cnt) {
                cnt++;
                if (cnt > n) {
                    cnt = 1;
                    cout << cnt << " ";
                    continue;
                }
                cnt++;
                cout << cnt << " ";
            }
            else {
                cnt++;
                if (cnt > n) {
                    cnt = 1;
                    cout << cnt << " ";
                    continue;
                }
                cout << cnt << " ";
            }
        }
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