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
    vint s(5);
    for (size_t i = 1; i <= 4; i++) {
        cin >> s[i];
    }
    vint hw(25, 0);
    int ans = 0;
    for (size_t i = 1; i <= 4; i++) {
        int sum = 0;
        vint dp(1e6, 0);
        for (size_t j = 1; j <= s[i]; j++) {
            cin >> hw[j];
            sum += hw[j];
        }
        //dp[k] --> 有限数的和内最接近 sum/2 的较小的和
        for (size_t j = 1; j <= s[i]; j++) {
            for (size_t k = sum / 2; k >= hw[j]; k--) {
                dp[k] = max(dp[k], dp[k - hw[j]] + hw[j]);
            }
        }
        ans += sum - dp[sum / 2];
    }
    cout << ans;
    return 0;
}