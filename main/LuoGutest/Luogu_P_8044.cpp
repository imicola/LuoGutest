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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) {
        string temps;
        int k = s2.size() - s1.size();
        while (k--) {
            temps += "0";
        }
        s1 = temps + s1;
    }
    if (s2.size() < s1.size()) {
        string temps;
        int k = s1.size() - s2.size();
        while (k--) {
            temps += "0";
        }
        s2 = temps + s2;
    }
    // cout << s1 << endl << s2;
    for (size_t i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) {
            s2[i] = 'r';
        }
        else if (s1[i] < s2[i]) {
            s1[i] = 'r';
        }
    }
    string res;
    for (auto &&i : s1) {
        if (i != 'r') res += i;
    }
    while (*res.begin() == '0' && res.size() > 1) res.erase(res.begin());
    cout << (res.empty() ? "YODA" : res) << endl;
    res = "";
    for (auto &&i : s2) {
        if (i != 'r') res += i;
    }
    while (*res.begin() == '0' && res.size() > 1) res.erase(res.begin());
    cout << (res.empty() ? "YODA" : res) << endl;
    return 0;
}