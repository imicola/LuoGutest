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

void solve()
{
    int n, k;
    cin >> n >> k;
    k--;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
        cnt += b;
    }
    int ans = 0;
    int count = 0;
    vint hash(4, 0);
    for (auto &&[ai, bi] : mp) {
        if (bi < 3) ans += bi;
        if (bi >= 3) {
            // count += bi / 3;
            ans += 2;
            bi -= 2;
            hash[3] += bi / 3;
            hash[bi % 3]++;
        }
    }
    for (int i = 3; i > 0; i--) {
        if (hash[i] < k) {
            ans += i * hash[i];
            k -= hash[i];
            // hash[i] = 0;
        }
        else {
            ans += i * k;
            hash[i] -= k;
            k = 0;
            break;
        }
    }
    if (k == 0 && hash[1] + hash[2] + hash[3] > 0)
        cout << ans + 1 << endl;
    else
        cout << -1 << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}