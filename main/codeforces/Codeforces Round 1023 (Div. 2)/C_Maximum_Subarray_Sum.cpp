//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


//TODO: check
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vint a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int NEG = -1000000000000000LL; // -1e15，用来切断
    vint zeros;
    zeros.reserve(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros.push_back(i);
    }
    int cur = 0, best_known = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cur = max(0LL, cur + a[i]);
            best_known = max(best_known, cur);
        }
        else {
            cur = 0;
        }
    }
    if (best_known > k) {
        cout << "No" << endl;
        return;
    }
    if (best_known == k) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                cout << NEG << ' ';
            else
                cout << a[i] << ' ';
        }
        cout << endl;
        return;
    }
    if (zeros.empty()) {
        cout << "No" << endl;
        return;
    }
    vint left_max(n, 0), right_max(n, 0);
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            t = max(0LL, t + a[i]);
        }
        else {
            t = 0;
        }
        left_max[i] = t;
    }
    t = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            t = max(0LL, t + a[i]);
        }
        else {
            t = 0;
        }
        right_max[i] = t;
    }
    bool found = false;
    vint ans;
    ans.reserve(n);
    for (int pos : zeros) {
        int L = (pos > 0 ? left_max[pos - 1] : 0);
        int R = (pos + 1 < n ? right_max[pos + 1] : 0);
        // 令 L + x + R = k
        int x = k - (L + R);
        if (abs(x) <= 1000000000000000000LL) {
            // 构造解
            found = true;
            ans = a;
            // 其它未知都设 NEG
            for (int z : zeros) ans[z] = NEG;
            // pos 处放 x
            ans[pos] = x;
            break;
        }
    }
    if (!found) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
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