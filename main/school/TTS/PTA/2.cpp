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
    // for (auto &&i : res) {
    //     for (auto &&i2 : i) {
    //         cout << i2 << " ";
    //     }
    //     cout << endl;
    // }
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
    unordered_set<int> out;
    for (size_t i = 0; i < res[0].size(); i++) {
        for (size_t j = 0; j < res.size(); j++) {
            for (size_t k = j + 1; k < res.size(); k++) {
                if (res[j][i] > res[k][i] && out.find(j) == out.end()) {
                    out.insert(j);
                    break;
                }
            }
        }
    }
    cout << res[0].size() << endl;
    for (size_t i = 0; i < res.size(); i++) {
        if (out.find(i) == out.end()) {
            vint ress = res[i];
            for (size_t i = 0; i < ress.size(); i++) {
                if (i == ress.size() - 1) {
                    cout << ress[i];
                    continue;
                }
                cout << ress[i] << " ";
            }
            return;
        }
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