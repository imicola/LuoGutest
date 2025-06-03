//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vector<int> prime;
vector<bool> not_prime(1e7);

void Euler(const long long &n)
{
    not_prime.resize(n + 1, false);
    for (size_t i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (auto &&j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v) {
        cin >> i;
    }
    int sumv = 0, sump = 0, ans = 0;
    ranges::sort(v, greater<int>{});
    for (size_t i = 0; i < n; i++) {
        sumv += v[i];
        sump += prime[i];
        if (sumv >= sump) ans = i + 1;
    }
    cout << n - ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    Euler(1e7);
    while (T--) {
        solve();
    }
    return 0;
}