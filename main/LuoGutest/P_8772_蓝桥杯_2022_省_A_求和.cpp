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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    vint v(T + 1, 0);
    vint parsum(T + 1, 0);
    for (size_t i = 1; i <= T; i++) {
        cin >> v[i];
    }
    int ans = 0;
    parsum[T] = v[T];
    for (int i = T - 1; i >= 0; i--) {
        parsum[i] = parsum[i + 1] + v[i];
    }
    for (size_t i = 1; i <= T; i++) {
        ans += v[i] * (parsum[i] - v[i]);
    }

    cout << ans;
    return 0;
}