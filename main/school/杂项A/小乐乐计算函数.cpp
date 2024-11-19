//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

double f(int a, int b, int c)
{
    double m = (max(max(a + b, b), c)) / (max(max(a, b + c), c) + max(max(a, b), b + c) * 1.0);
    return m;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    double ans = f(a, b, c);
    printf("%.2f", ans);
    return 0;
}