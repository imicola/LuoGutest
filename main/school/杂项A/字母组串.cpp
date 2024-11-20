//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

int count(int a, int b, int c, int n)
{
    int ans = 0;
    if (n == 0) return 1;
    if (a > 0) ans += count(a - 1, b, c, n - 1);
    if (b > 0) ans += count(a, b - 1, c, n - 1);
    if (c > 0) ans += count(a, b, c - 1, n - 1);
    return ans;
}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << count(a, b, c, n);
    return 0;
}