//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;

bool f(int n)
{
    if (n == 2) return 1;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (!f(n)) cout << "yes";
    else
        cout << "no";
    return 0;
}