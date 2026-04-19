//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vint v(n + 1);
    vint vk(k);
    for (i64 i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (i64 i = 0; i < k; i++) {
        cin >> vk[i];
    }
    vint b(n + 2, 0);
    i64 tar = v[vk[0]];
    for (i64 i = 1; i <= n; i++) {
        b[i] = (v[i] != tar ? 1 : 0);
    }
    vint diff(n + 2, 0);
    for (i64 i = 1; i <= n + 1; i++) {
        diff[i] = (b[i] ^ b[i - 1]);
    }
    i64 sum = 0;
    i64 maxx = -1;
    vk.emplace_back(n + 1);
    i64 tmp = 0;
    for (auto &&i : vk) {
        i64 res = 0;
        for (i64 j = tmp + 1; j <= i; j++) {
            if (diff[j] == 1) {
                res++;
                sum++;
            }
        }
        maxx = max(res, maxx);
        tmp = i;
    }

    cout << max(sum / 2, maxx) << endl;
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