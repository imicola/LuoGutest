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
    string n;
    cin >> n;
    if (n.size() < 2) {
        cout << 0 << endl;
        return;
    }
    map<int, int> mp;
    int cnt = 0, cnt2 = 0, cnt0 = 0;
    for (auto &&i : n) {
        if (i != '0')
            cnt++;
        else
            cnt0++;
    }
    for (int i = n.size() - 1; i >= 0; i--) {
        while (n[i] == '0') {
            cnt2++;
            i--;
        }
        // cout <<"1 " <<  cnt2 << endl;
        break;
    }

    cout << (cnt - 1) + (cnt2) << endl;
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