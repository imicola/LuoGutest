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

const int MOD = 998244353;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vint num(n);
        for (auto &&i : num) {
            cin >> i;
        }
        for (size_t i = 0; i < m; i++) {
            int l, r, d;
            cin >> l >> r >> d;
            for (size_t i = l; i <= r; i++) {
                num[i] += d;
            }
        }
        // 草，根本不会写，我认输！！！
        // 草，怎么有人第二题罚了19次啊，草那不就是我吗？
        // 看错题的下场
    }

    return 0;
}