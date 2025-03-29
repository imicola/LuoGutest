//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

vector<int> strfind(string s1, string s2)
{
    vector<int> res;
    int pos = s1.find(s2, 0);
    while ((pos = s1.find(s2, pos)) != -1) {
        res.emplace_back(pos);
        pos += s2.size();
    }
    return res;
}

void solve()
{
    string s, s1;
    getline(cin, s);
    getline(cin, s1);
    vector<int> ans = strfind(s, s1);
    for (auto &&i : ans) {
        cout << i << " ";
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