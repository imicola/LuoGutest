//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<char> vc(n + 1, '+');
    i64 up = 0, down = 0, un = 0;
    for (auto &&i : s) {
        if (i == '0') {
            up++;
        }
        else if (i == '1') {
            down++;
        }
        else {
            un++;
        }
    }
    if (k == n) {
        for (i64 i = 0; i < n; i++) {
            cout << '-';
        }
        cout << endl;
        return;
    }
    for (i64 i = 1; i <= up; i++) {
        vc[i] = '-';
    }
    for (i64 i = 1; i <= down; i++) {
        vc[n - i + 1] = '-';
    }
    for (i64 i = 1; i <= un && up + i <= n; i++) {
        vc[up + i] = '?';
        vc[n - down + 1 - i] = '?';
    }
    for (i64 i = 1; i <= n; i++) {
        cout << vc[i];
    }
    cout << endl;
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