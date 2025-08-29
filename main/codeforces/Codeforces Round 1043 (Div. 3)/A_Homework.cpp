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
    int n;
    string a, b, c;
    int m;
    cin >> n;
    cin >> a;
    cin >> m;
    cin >> b;
    cin >> c;
    string s = a;
    for (size_t i = 0; i < m; i++) {
        if (c[i] == 'D') {
            s.push_back(b[i]);
        }
        else {
            s.insert(s.begin(), b[i]);
        }
    }
    cout << s << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}