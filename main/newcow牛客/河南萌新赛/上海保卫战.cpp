//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

vector<int> prime;
bitset<(long long)1e9> not_prime;

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

bool check_p(i64 x)
{
    if (x <= 2) return 0;
    for (i64 i = 2; i <= x / i; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve()
{
    i64 n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 + 1;
        return;
    }
    else {
        i64 p = 0;
        if (check_p(n)) {
            cout << 2 << endl;
            return;
        }
        for (auto &&i : prime) {
            if (n % i == 0) {
                p = i;
                break;
            }
        }
        n -= p;
        // cout << n << endl;
        cout << n / 2 + 2;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    Euler(1e7);
    while (T--) {
        solve();
    }
    return 0;
}