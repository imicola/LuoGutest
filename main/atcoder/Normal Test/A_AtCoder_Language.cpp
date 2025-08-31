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
    string s1;
    cin >> s1;
    if (s1 == "red") {
        cout << "SSS" << endl;
        return;
    }
    if (s1 == "blue") {
        cout << "FFF" << endl;
        return;
    }
    if (s1 == "green") {
        cout << "MMM" << endl;
        return;
    }
    cout << "Unknown" << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}