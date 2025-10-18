//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

static inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void solve()
{
    i64 n;
    cin >> n;
    queue<i64> cnt1;
    queue<i64> cnt2;
    vint v(2e5);
    for (i64 i = 0; i < n; i++) {
        i64 x = 0;
        x = read();
        v[x]++;
    }
    for (i64 i = 0; i <= 1e5 + 10; i++) {
        while (v[i]) {
            v[i]--;
            cnt1.push(i);
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        vint p1 = {0, 0};
        for (i64 j = 0; j < 2; j++) {
            if (cnt2.empty() || (cnt1.front() < cnt2.front() && !cnt1.empty())) {
                p1[j] = cnt1.front();
                cnt1.pop();
            }
            else {
                p1[j] = cnt2.front();
                cnt2.pop();
            }
        }
        ans += p1[0] + p1[1];
        cnt2.push(p1[0] + p1[1]);
        if (cnt1.empty() && cnt2.size() == 1) break;
    }
    cout << ans << endl;
}
signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}