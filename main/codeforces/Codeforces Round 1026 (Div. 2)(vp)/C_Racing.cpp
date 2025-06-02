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


// TODO 写错误分析与题解
// 
void solve()
{
    int n;
    cin >> n;
    vint v(n + 1, 0);
    for (size_t i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vint under(n + 1, -1), up(n + 1, INT_MAX);
    int under_max = 0, under_idx = 0;
    int undmx = 0;
    for (size_t i = 1; i <= n; i++) {
        cin >> under[i] >> up[i];
        undmx = max(undmx, under[i]);
        under[i] = undmx;
        if (under[i] > under_max) {
            under_max = under[i];
            under_idx = i;
        }
    }
    int upmn = INT_MAX;
    for (int i = n; i >= 0; i--) {
        upmn = min(up[i], upmn);
        up[i] = upmn;
    }
    int now = 0;
    vint ans(n + 1, -114);
    for (size_t i = 1; i <= under_idx; i++) {
        if (v[i] != -1) {
            now += v[i];
            ans[i] = v[i];
        }
        else {
            if (now < up[i]) {
                ans[i] = 1;
                now++;
            }
            else {
                ans[i] = 0;
            }
        }
        // cout << i << " now:" << now << " up: " << up[i] << endl;
        if (now > up[i] || now < under[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (size_t i = under_idx + 1; i <= n; i++) {
        if (v[i] != -1) {
            now += v[i];
            ans[i] = v[i];
        }
        else {
            ans[i] = 0;
        }
        if (now > up[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (size_t i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
void solve1()
{
    int n;
    cin >> n;
    vint d(n);
    for (auto &&i : d) {
        cin >> i;
    }
    vint l(n), r(n);
    for (size_t i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    int left = 0;
    stack<int> last;
    for (size_t i = 0; i < n; i++) {
        if (d[i] == -1) {
            last.emplace(i);
        }
        else {
            left += d[i];
        }
        while (left < l[i]) {
            if (last.empty()) {
                cout << -1 << endl;
                return;
            }
            d[last.top()] = 1;
            left++;
            last.pop();
        }
        while (left + last.size() > r[i]) {
            if (last.empty()) {
                cout << -1 << endl;
                return;
            }
            d[last.top()] = 0;
            last.pop();
        }
    }
    for (auto &&i : d) {
        cout << max(0ll, i) << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}