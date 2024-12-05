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

bool cmp(pair<double, int> a, pair<double, int> b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<double, int>> coin(n);
    for (auto &&[val, wei] : coin) {
        double m, v;
        cin >> m >> v;
        val = (v / m);
        wei = m;
    }
    sort(all(coin), cmp);
    double ans = 0;
    for (size_t i = 0; i < n; i++) {
        if (t >= coin[i].second) {
            ans += coin[i].second * coin[i].first;
            t -= coin[i].second;
        }
        else {
            ans += coin[i].first * t;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}