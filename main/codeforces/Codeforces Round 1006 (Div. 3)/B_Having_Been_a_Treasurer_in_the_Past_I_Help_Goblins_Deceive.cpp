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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3) {
        cout << 0 << endl;
        return;
    }
    int n_1 = 0, n_0 = 0;
    for (auto &&i : s) {
        if (i == '-') n_0++;
        if (i == '_') n_1++;
    }
    if(n_0 < 2){
        cout << 0 << endl;
        return;
    }
    if(n_0 % 2 == 0){
        cout << (n_0/2) * n_1 * (n_0/2) << endl;
        return;
    }
    else
    {
        cout << (n_0 / 2 + 1) * n_1 * (n_0 / 2) << endl;
        return;
    }
    
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}