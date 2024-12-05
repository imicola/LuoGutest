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
vector<bool> isnotprime(1e6);

void epri(int n)
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
    epri(t);
    for (size_t i = 4; i <= t; i += 2) {
        for (size_t j = 0;prime[j] <= i ; j++)
        {
            for (size_t k = j; prime[k] <= i; k++)
            {
                if(prime[j] + prime[k] == i){
                    printf("%d=%d+%d\n", i, prime[j], prime[k]);
                    goto P;
                }
            }
        }
        P:
    }

    return 0;
}