//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int f(int n){
    return (n & 1 ? 3 * n + 1 : n / 2);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}