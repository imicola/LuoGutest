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

void solve()
{
    int n, s;
    cin >> n >> s;
    map<int, int> m;
    int sum = 0;
    int sum_k = 0;
    for (size_t i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        m[c] += p;
        sum += p * c;
        sum_k += p;
    }
    for (size_t i = 1; i < 1e6; i++) {
        if (s > sum_k) break;
        sum += s - sum_k;
        sum_k -= m[i];
    }
    cout << sum;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}