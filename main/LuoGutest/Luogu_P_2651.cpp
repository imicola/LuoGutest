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
    int n;
    cin >> n;
    vint res(n);
    for (size_t i = 0; i < n; i++) {
        cin >> res[i];
    }
    int res_x = res[1];
    for (size_t i = 0; i < n; i++) {
        if (i != 1) res_x /= gcd(res[i], res_x);
        if (res_x == 1) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
/* 
a1肯定是分子,a2肯定是分母,那么尽可能多的是a3以后的变为分子,怎么办呢?
很简单
a1/(a2/a3/a4/...)=a1a3a4.../a2
所以我们只要确认a1a3a4.../a2是否是整数.
如果你非要写高精我也不拦你.
但是如果进行约分,知道a2能被约分成1,那么就是整数.
每次将a2=a2/gcd(a2,ai),i=(1,3,4,5...)即可约分
*/