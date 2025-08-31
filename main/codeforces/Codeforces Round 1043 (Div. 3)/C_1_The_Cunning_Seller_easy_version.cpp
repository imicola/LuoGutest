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

int ksm(int a, int b)
{
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vint ans;
    while (n > 0) {
        ans.emplace_back(n % 3);
        n /= 3;
    }
    // ranges::reverse(ans);
    int ans1 = 0;
    for (size_t i = 0; i < ans.size(); i++) {
        int p = ans[i];
        ans1 += p * (ksm(3, i + 1) + i * ksm(3, i - 1));
    }
    cout << ans1 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}