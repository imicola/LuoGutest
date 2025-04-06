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

void solve()
{
    string s;
    cin >> s;
    string ss = s;
    reverse(all(s));
    if (ss == s) {
        cout << "Yes" << endl;
        return;
    }
    auto check = [&](int a) -> bool {
        for (size_t i = 0, j = a; i < j; i++, j--) {
            if (ss[i] != ss[j]) {
                return 0;
            }
        }
        return 1;
    };
    for (int i = ss.size() - 1; i >= 0; i--) {
        if (check(i)) {
            cout << "Yes" << endl;
            return;
        }
        if (ss[i] != 'l' && ss[i] != 'q' && ss[i] != 'b') {
            break;
        }
    }
    cout << "No" << endl;
}
//
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