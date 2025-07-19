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

struct vv
{
    int a, b, diff;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vv> v(m);
    for (auto &&[i, j, k] : v) {
        cin >> i >> j;
        k = i - j;
    }
    ranges::sort(v, [](vv i, vv j) { return i.diff < j.diff; });
    int cnt = 0;
    int now = n;
    int idx = 0;
    for (auto &&[i,j,dif] : v)
    {
        if(now >= i){
            int k = (now - i) / dif;
            if(k > 0){
                cnt += k;
                now -= k * dif;
            }
            if(now >= i){
                cnt++;
                now -= dif;
            }
        }
    }
    
    cout << cnt << endl;
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