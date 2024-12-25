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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vint v(t);
    double count = 0;
    for (auto &&i : v) {
        cin >> i;
        if (i < 60) count++;
    }
    if ((count / (t * 1.0)) >= 0.6) {
        for (size_t i = 0; i < t; i++) {
            cout << sqrt(v[i] * 1.0) * 10 << ": "[i == t - 1];
        }
    }
    else {
        for (size_t i = 0; i < t; i++) {
            cout << v[i] << ": "[i == t - 1];
        }
    }

    return 0;
}