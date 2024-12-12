#pragma GCC optimize(3)
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

int fastpow(int k, int l)
{
    if (l == 0 || k == 0) return 1;
    int ans = 1;
    while (l > 0) {
        if (l & 1) {
            ans *= k;
        }
        k *= k;
        l >>= 1;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;
        bool falg = 1;
        int result = 1;
        if (k == 0 && l <= 0) {
            cout << "0 ";
            falg = 0;
        }
        for (size_t i = 0; result <= r; i++) {
            result = fastpow(k, i);
            if (result > r) break;
            if (result >= l) {
                cout << result << " ";
                falg = 0;
            }
            if (k == 0 || k == 1) break;
            // result = fastpow(k, i);
        }
        if (falg == 1) cout << "None.";
        cout << endl;
    }
    return 0;
}