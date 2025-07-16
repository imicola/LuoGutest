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
    cin >> n;
    string s;
    int cnt = 0;
    for (size_t i = 0; i < n; i++) {
        int l;
        char c;
        cin >> c >> l;
        cnt += l;
        if(cnt > 100)
        {
            cout << "Too Long" << endl;
            return;
        }
        for (size_t i = 0; i < l; i++)
        {
            s += c;
        }
    }
    cout << s << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}