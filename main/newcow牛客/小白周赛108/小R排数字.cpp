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

vector<string> st = {"2", "4", "6", "8"};

int strcount(string s, string ch)
{
    size_t it = 0;
    int ans = 0;
    while ((it = s.find(ch, it)) != string::npos) {
        it += ch.size();
        ans++;
    }
    return ans;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a % 4 == 0) {
            cout << "YES" << endl;
            continue;
        }
        string s = to_string(a);
        int ans = 0;
        for (size_t i = 0; i < 4; i++) {
            ans += strcount(s, st[i]);
        }
        if (ans > 1) {
            cout << "YES" << endl;
            continue;
        }
        int k1 = s.find("1");
        int k2 = s.find("2");
        int k3 = s.find("3");
        int k5 = s.find("5");
        int k6 = s.find("6");
        int k7 = s.find("7");
        int k9 = s.find("9");
        if ((k1 != -1 && k2 != -1) || (k1 != -1 && k6 != -1) || (k2 != -1 && k3 != -1) || (k3 != -1 && k6 != -1) ||
            (k2 != -1 && k5 != -1) || (k7 != -1 && k6 != -1) || (k9 != -1 && k2 != -1) || (k9 != -1 && k6 != -1)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}
// 178
// 13774
// 17324
// 2212
// 12 16  32 36