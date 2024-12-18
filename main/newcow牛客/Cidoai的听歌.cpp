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
    int n;
    cin >> n;
    vint num(n);
    for (auto &&i : num) {
        cin >> i;
    }
    sort(all(num));
    int minn = num[0];
    int maxx = num[num.size() - 1];
    int ans = 0;
    
    // cout << 
    // while (minn != maxx) {
    //     minn++;
    //     ans++;
    //     if (minn == maxx) break;
    //     maxx--;
    //     ans++;
    // }
    // cout << ans << " " << minn;
}
// 2 3 4 5 6
// 2 3 4 5
// 2 2 3 3 4 4 4