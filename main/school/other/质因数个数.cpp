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

int N = 1e9;
vint not_prime(N);
vint prime;

void Elur(int n)
{
    for (size_t i = 2; i <= n; i++) {
        if (!not_prime[i]) prime.emplace_back(i);
        for (auto &&j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

bool cprime(int n)
{
    if (n < 2) return 0;
    for (size_t i = 2; i <= n / i; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    Elur((int)sqrt(n));
    if (cprime(n)) {
        cout << 1;
        return;
    }
    for (auto &&i : prime) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            ans++;
        }
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}