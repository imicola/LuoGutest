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
template <typename T> using vec = vector<T>;
const constexpr i64 MOD = 998244353;

vector<i64> prime;
bitset<(i64)1e9> not_prime;

void Euler(long long n)
{
    for (size_t i = 2; i <= n; i++) {
        // 如果该数标记为 0 即 非(非素数),计入素数数组
        if (!not_prime[i]) {
            prime.push_back(i);
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
    i64 n;
    cin >> n;
    vint v(n);
    set<i64> st;
    i64 g = -1;
    for (auto &&i : v) {
        cin >> i;
        if (g == -1) g = i;
        g = gcd(g, i);
    }
    for (auto &&p : prime) {
        if(g % p != 0){
            cout << p << endl;
            return;
        }
    }
    i64 k = __gcd(5,5);
    i64 p = lcm(7, 8);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    Euler(1000);
    while (T--) {
        solve();
    }
    return 0;
}