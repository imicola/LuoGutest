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

vint prime;
vector<bool> isnotprime(3e6);

// 欧拉筛
void E_prime(int n)
{
    for (size_t i = 2; i <= n; i++) {
        if (!isnotprime[i]) {
            prime.emplace_back(i);
        }
        for (auto &&j : prime) {
            if (i * j > n) break;
            isnotprime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    E_prime(t);
    bool fl = 0;
    for (size_t i = 1; i < prime.size() && prime[i] <= t; i++) {
        if (prime[i] - prime[i - 1] == 2) {
            cout << prime[i - 1] << " " << prime[i] << endl;
            fl = 1;
        }
    }
    if (!fl) cout << "none";
    return 0;
}