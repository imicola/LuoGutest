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

bool comp(vint a, vint b)
{
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return 0;
}

vint ans;
vvint res;
int maxcnt = 0;
int px = 0;
void dfs(const vvint &vv, int start, int cnt, vint ans)
{
    if (vv[start].size() == 0) {
        if (cnt > maxcnt) {
            maxcnt = cnt;
            res.clear();
            res.emplace_back(ans);
            return;
        }
        if (cnt == maxcnt) {
            res.emplace_back(ans);
        }
        return;
    }
    for (auto &&i : vv[start]) {
        ans.push_back(i);
        dfs(vv, i, cnt + 1, ans);
        ans.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;
    vvint vv(n + 1);
    for (size_t i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (size_t j = 0; j < p; j++) {
            int k;
            cin >> k;
            vv[i].emplace_back(k);
        }
    }
    for (size_t i = 0; i < n; i++) {
        ans.emplace_back(i);
        dfs(vv, i, 0, ans);
        ans.clear();
    }
    if (res.size() == 1) {
        cout << res[0].size() << endl;
        for (size_t i = 0; i < res[0].size(); i++) {
            if (i == res[0].size() - 1) {
                cout << res[0][i];
                continue;
            }
            cout << res[0][i] << " ";
        }
        return;
    }
    cout << res[0].size() << endl;
    ranges::stable_sort(res, [](vint a, vint b) { return comp(a, b); });
    for (size_t i = 0; i < res[0].size(); i++) {
        if (i == res[0].size() - 1) {
            cout << res[0][i];
            return;
        }
        cout << res[0][i] << " ";
    }
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}