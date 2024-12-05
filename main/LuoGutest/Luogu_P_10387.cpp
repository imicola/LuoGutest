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
    int n, s;
    cin >> n >> s;
    map<int, int> k;
    vpii kp(n);
    int kt = 0, ans = 0, total = 0;
    for (auto &&[pi, ci] : kp) {
        cin >> pi >> ci;
        k[ci] += pi;
        total += pi * ci;
        kt += pi;
    }
    for (size_t i = 1; i < 1e6; i++) {
        if (s > kt) break;
        ans += s;
        total -= kt;
        kt -= k[i];
    }
    cout << ans + total;
    return 0;
}