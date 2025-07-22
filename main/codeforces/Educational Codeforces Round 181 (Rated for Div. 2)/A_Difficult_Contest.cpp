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
    string s;
    cin >> s;
    int ok = 0;
    int cntn = 0, cntt = 0;
    for (size_t i = 0; i + 2 < s.size(); i++) {
        if (s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') {
            // swap(s[i + 1], s[i + 2]);
            ok = 1;
        }
        if (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T') {
            // swap(s[i + 1], s[i]);
            ok = 1;
        }
    }
    if (!ok) {
        cout << s << endl;
        return;
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            cntt++;
            s[i] = '%';
        }
        if (s[i] == 'N') {
            cntn++;
            s[i] = '%';
        }
    }

    for (size_t i = 0; i < cntt; i++) {
        cout << 'T';
    }
    for (size_t i = 0; i < cntn; i++) {
        cout << 'N';
    }
    for (auto &&i : s) {
        if (i != '%') cout << i;
    }
    cout << endl;
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