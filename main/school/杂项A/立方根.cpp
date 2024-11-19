//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    double n;
    cin >> n;
    double ans = pow(n, 1 / (3 * 1.0));
    printf("%.3f", ans);
    return 0;
}