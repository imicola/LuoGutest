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

void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    vint arr(n);
    for (auto &&i : arr) {
        char temp;
        cin >> temp;
        i = (temp == 'R' ? 1 : -1);
    }
    int cnt = 0;
    int step = 0;
    for (size_t i = 0; i < n; i++) {
        x += arr[i];
        step++;
        if (step > k) {
            cout << cnt << endl;
            return;
        }
        if (x == 0) {
            cnt++;
            break;
        }
    }
    if (step >= k || cnt == 0) {
        cout << cnt << endl;
        return;
    }
    int s = 0;
    x = 0;
    for (size_t i = 0; i < n; i++) {
        x += arr[i];
        step++;
        if (step > k) {
            cout << cnt << endl;
            return;
        }
        if (x == 0) {
            cnt++;
            s = i + 1;
            break;
        }
    }
    if (step >= k || cnt == 1) {
        cout << cnt << endl;
        return;
    }
    cnt += (k - step) / s;
    // cout << "s: " << s << endl;
    cout << cnt << endl;
    // cout << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        // cout << "T: " << T << " ";
        solve();
    }
    return 0;
}