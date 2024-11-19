//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;

vector<bool> isn_prime(1e6);
vector<int> prime;
int eprime(int n)
{
    int ans = 0;
    for (size_t i = 2; i <= n; i++) {
        if (isn_prime[i] == 0) {
            prime.push_back(i);
            ans++;
        }
        for (auto &&j : prime) {
            if (i * j > n) break;
            isn_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << eprime(n) << endl;
    }

    return 0;
}