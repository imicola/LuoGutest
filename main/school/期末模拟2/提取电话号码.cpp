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
    string s;
    getline(cin, s);
    string ph;
    string qk = "";
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ph += s[i];
        }
        if (i > 0) {
            if ((s[i] < '0' || s[i] > '9') && s[i - 1] >= '0' && s[i - 1] <= '9') {
                cout << ph << endl;
                ph.clear();
            }
        }
    }
    cout << ph;
    return 0;
}