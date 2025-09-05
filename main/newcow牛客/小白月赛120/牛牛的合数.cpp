//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

set<int> prime;
bitset<(i64)1e9> not_prime;

void Euler(i64 n)
{
    for (size_t i = 2; i <= n; i++) {
        // 如果该数标记为 0 即 非(非素数),计入素数数组
        if (!not_prime[i]) {
            prime.insert(i);
        }
        // 筛出小于n的该素数的倍数
        // 当然这么写不优雅，我们可以用范围for替代繁琐的prime[j];
        for (auto &&j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

void solve()
{
    int x;
    cin >> x;
    if (x <= 3) {
        cout << -1 << endl;
        return;
    }
    if (prime.contains(x)) {
        cout << 1 << endl;
        return;
    }
    else {
        if (x & 1) {
            cout << 1 << endl;
            return;
        }
        else {
            cout << 2 << endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    Euler(1e4);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}