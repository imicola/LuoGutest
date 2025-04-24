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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2) {
        cout << "YES" << endl;
        return;
    }
    if (s2.size() < s1.size() || s1[0] != s2[0]) {
        cout << "NO" << endl;
        return;
    }
    s1 += "E";
    s2 += "E";
    vint s1LR, s2LR;
    int cnt = 0;
    for (size_t i = 0; i < s1.size() - 1; i++) {
        cnt++;
        if (s1[i] != s1[i + 1]) {
            s1LR.emplace_back(cnt);
            cnt = 0;
        }
    }
    for (size_t i = 0; i < s2.size() - 1; i++) {
        cnt++;
        if (s2[i] != s2[i + 1]) {
            s2LR.emplace_back(cnt);
            cnt = 0;
        }
    }
    if (s1LR.size() != s2LR.size()) {
        cout << "NO" << endl;
        return;
    }
    for (size_t i = 0; i < s1LR.size(); i++) {
        if (s2LR[i] < s1LR[i] || s2LR[i] > s1LR[i] * 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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