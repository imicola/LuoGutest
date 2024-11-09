//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int arr[25][25][25];
bool vis[25][25][25];

int w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (vis[a][b][c]) return arr[a][b][c];
    else if (a < b && b < c) {
        arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    vis[a][b][c] = 1;
    return arr[a][b][c];
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (a == b && b == c && a == -1) break;
        printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}