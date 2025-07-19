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
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    vint k(60, 0);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 60; j++) {
            if (((v[i] >> j) & 1) == 1) {
                k[j]++;
            }
        }
    }
    for (auto &&i : v)
    {
        int hight = 63 - __builtin_clzll(i);
        if(k[hight] > 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
// 3      1
// 5     10
// 7   1 10
// 9  10 01
//21 101 01
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