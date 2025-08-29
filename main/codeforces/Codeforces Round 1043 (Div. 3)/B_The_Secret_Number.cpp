//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
#define double long double
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
    double n;
    cin >> n;
    double x = 0;
    vint ans;
    for (size_t i = 1; i < 19; i++) {
        if ((n / (double)(ksm(10, i) + 1)) == (int)((int)n / (ksm(10, i) + 1))) {
            ans.emplace_back(n / (ksm(10, i) + 1));
        }
    }
    cout << ans.size() << endl;
    ranges::sort(ans);
    if(ans.size() == 0){
        return;
    }
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
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