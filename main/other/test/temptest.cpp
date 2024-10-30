#include <iostream>
using namespace std;
using LL = long long;

int n, k[25];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> k[i];
    LL a, b, ans = 1e18;
    for (LL state = 0; state < 1LL << n; state++) {
        a = 0, b = 0;
        for (int i = 0; i < n; i++)
            if (state >> i & 1) a += k[i];
            else b += k[i];
        ans = min(ans, max(a, b));
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}