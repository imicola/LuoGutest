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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto &&i : s) {
        if (i == '0')
            cnt0++;
        else
            cnt1++;
    }
    if ((cnt0 == 0 || cnt1 == 0)) {
        cout << ((k == n / 2) ? "YES" : "NO") << endl;
        return;
    }
    int km = abs(cnt0 - cnt1) / 2;
    int kmx = 0;
    if (cnt0 % 2 == 0) {
        kmx = n / 2;
    }
    else {
        kmx = (n / 2) - 1;
    }
    cout << ((k >= km && k <= kmx && k % 2 == km % 2) ? "YES" : "NO") << endl;
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