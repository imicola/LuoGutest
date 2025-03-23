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
    int n, m, s;
    cin >> n >> m >> s;
    map<int, string> sp;
    for (size_t i = 1; i <= n; i++) {
        string sn;
        cin >> sn;
        sp[i] = sn;
    }
    stack<char> sk;
    int p;
    while (cin >> p) {
        if (p == -1) break;
        if (p != 0) {
            if (sk.size() < s) {
                if (sp[p].size() > 0) {
                    char ch = sp[p].front();
                    sk.push(ch);
                    sp[p].erase(sp[p].begin());
                }
                else if (sp[p].size() == 0) {
                    continue;
                }
            }
            else if (sk.size() >= s) {
                if (sp[p].size() > 0) {
                    cout << sk.top();
                    sk.pop();
                    char ch = sp[p].front();
                    sk.push(ch);
                    sp[p].erase(sp[p].begin());
                }
                else if (sp[p].size() == 0) {
                    continue;
                }
            }
        }
        else {
            if (sk.empty()) {
                continue;
            }
            else {
                cout << sk.top();
                sk.pop();
            }
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