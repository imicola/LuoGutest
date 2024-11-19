//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;

int complexnum(int m, int n)
{
    if (n == m || m == 0) return 1;
    return complexnum(m, n - 1) + complexnum(m - 1, n - 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    cout << complexnum(m, n);
    return 0;
}