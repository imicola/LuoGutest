//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    double ans = 0;
    ans = a / 100.0 * 3 + b / 100.0 * 20 + c * 6;
    printf("%.1f", ans);
    return 0;
}