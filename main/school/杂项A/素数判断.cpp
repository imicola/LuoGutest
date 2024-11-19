// #pragma GCC optimize(2)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

bool isprime(int n)
{
    if (n < 2) return 0;
    for (size_t i = 2; i <= n / i; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void solve(int x)
{
    set<int> hashprime;
    while (x % 2 == 0) {
        hashprime.insert(2);
        x /= 2;
    }
    for (size_t i = 3; i <= x / i; i++) {
        while (x % i == 0) {
            hashprime.insert(i);
            x /= i;
        }
    }
    if (x > 2 && isprime(x)) hashprime.insert(x);
    for (auto &&i : hashprime) {
        cout << i << " ";
    }
}

void f(int a)
{
    if (isprime(a) == 1) {
        cout << "isprime" << endl << a;
    }
    else {
        cout << "noprime" << endl;
        int k = a;
        solve(k);
    }
    cout << endl;
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        f(n);
    }
    
    return 0;
}