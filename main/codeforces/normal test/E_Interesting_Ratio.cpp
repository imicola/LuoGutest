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

vint not_prime(1e7 + 10, 0);
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

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (auto &&i : prime) {
        ans += n / i;
        if (i > n) {
            break;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Elur(1e7);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}