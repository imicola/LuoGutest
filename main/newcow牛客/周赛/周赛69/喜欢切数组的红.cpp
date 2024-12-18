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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    int sum = 0;
    cin >> t;
    vint a(t + 1, 0);
    for (size_t i = 0; i < t; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << 0;
        return 0;
    }
    int trage = sum / 3;
    int flag = 0;
    int ans = 0;
    int k = 0;
    for (size_t i = 0; i < t - 1; i++) {
        flag += a[i];
        if (flag == 2 * trage) {
            ans += k;
        }
        if (flag == trage) {
            k++;
        }
    }
    cout << ans;
    return 0;
}