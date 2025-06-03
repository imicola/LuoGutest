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
    int n, m;
    cin >> n >> m;
    map<int, vint> cla;
    set<int> fl;
    int maxf = 0, minf = INT_MAX;
    for (size_t i = 0; i < m; i++) {
        string s;
        cin >> s;
        int x = stoll(s.substr(s.size() - 2));
        int f = stoll(s.substr(0, s.size() - 2));
        // cout << f << " " << x << endl;
        cla[f].emplace_back(x);
        fl.insert(f);
        maxf = max(maxf, f);
        minf = min(minf, f);
    }
    vint vfl(all(fl));
    vpii ans(n);
    int p = 0;
    int cnt = 0;
    for (size_t i = 0; i < n;) {
        if (p >= 0 && p < vfl.size()) {
            int cntf = vfl[p];
            for (auto &&t : cla[cntf]) {
                if (i < n) {
                    ans[i].first =
                        stoll(to_string(cntf) + (to_string(t).size() < 2 ? "0" + to_string(t) : to_string(t)));
                    i++;
                }
            }
        }
        cnt++;
        if (cnt % 2 == 1) {
            int idx = vfl.size() - 1 - cnt / 2;
            p = (idx >= 0 && idx < vfl.size()) ? idx : 0;
        }
        else {
            int idx = cnt / 2;
            p = (idx >= 0 && idx < vfl.size()) ? idx : 0;
        }
        // cout << p << endl;
    }
    p = vfl.size() - 1;
    cnt = 0;
    for (size_t i = 0; i < n;) {
        if (p >= 0 && p < vfl.size()) {
            int cntf = vfl[p];
            for (auto &&t : cla[cntf]) {
                if (i < n) {
                    ans[i].second =
                        stoll(to_string(cntf) + (to_string(t).size() < 2 ? "0" + to_string(t) : to_string(t)));
                    i++;
                }
            }
        }
        cnt++;
        if (cnt % 2 == 1) {
            int idx = cnt / 2;
            p = (idx >= 0 && idx < vfl.size()) ? idx : vfl.size() - 1;
        }
        else {
            int idx = vfl.size() - 1 - cnt / 2;
            p = (idx >= 0 && idx < vfl.size()) ? idx : vfl.size() - 1;
        }
        // cout << p << endl;
    }
    for (auto &&i : ans) {
        for (int k = 0; k < 6; k++) {
            cout << (k % 2 == 0 ? i.first : i.second) << ' ';
        }
        cout << endl;
    }
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