#pragma GCC optimize(3)
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        int maxt = 0;
        unordered_map<int, int> num;
        for (size_t i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            num[temp]++;
            maxt = max(maxt, num[temp]);
        }
        vpii res(num.begin(), num.end());
        sort(all(res), [](const pii &a, const pii &b) { return a.second < b.second; });
        vint ans(maxt + 1, n);
        int sum = 0;
        int l = 1;
        for (auto &&[a, b] : res) {
            while (l < b) {
                ans[l] = n - sum;
                l++;
            }
            sum += b;
        }
        while (q--) {
            int k;
            cin >> k;
            if (k >= maxt) {
                cout << 0 << " ";
                continue;
            }
            cout << ans[k] << " ";
        }
        cout << endl;
    }

    return 0;
}