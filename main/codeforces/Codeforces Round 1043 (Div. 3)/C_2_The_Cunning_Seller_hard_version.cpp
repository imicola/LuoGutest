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
    int n, k;
    cin >> n >> k;
    int copyn = n;
    vint ans;
    while (n > 0) {
        ans.emplace_back(n % 3);
        n /= 3;
    }
    if (ans.size() == 0) ans.push_back(0);
    int t = 0;
    for (auto &&i : ans) {
        t += i;
    }
    if (t > k) {
        cout << -1 << endl;
        return;
    }
    vint powi(ans.size() + 1, 1);
    // ? 如何计算最小费用 dp？
    for (size_t i = 1; i <= ans.size(); i++) {
        powi[i] = powi[i - 1] * 3;
    }
    auto cost = [&](int x) {
        if (x == 0) return powi[1];
        return powi[x + 1] + (x * powi[x - 1]);
    };
    int ans1 = 0;
    for (size_t i = 0; i < ans.size(); i++) {
        int p = ans[i];
        if (p == 0) continue;
        ans1 += p * cost(i);
    }
    int m = k - ((k - t) & 1);
    if (m > copyn) m = copyn;
    int t2 = (m - t) / 2;
    if (t2 == 0) {
        cout << ans1 << endl;
        return;
    }
    for (int i = ans.size() - 1; i > 0 && t2 > 0; i--) {
        if (ans[i] == 0) continue;
        int s = min(t2, ans[i]);
        ans1 -= s * powi[i - 1];
        ans[i] -= s;
        ans[i - 1] += 3 * s;
        t2 -= s;
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