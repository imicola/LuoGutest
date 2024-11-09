//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;
    cout << a1 * n + ((n) * (n - 1) / 2) * (a2 - a1);
    return 0;
}