#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 10] = {0};
    int b[n + 10] = {0};
    int c[n + 10] = {0};
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++) {
        cin >> b[i];
        ans += b[i];
        c[i] = a[i] - b[i];
    }
    sort(c, c + n, greater<int>());
    for (size_t i = 0; i < k; i++) {
        ans += c[i];
    }
    cout << ans << endl;
    return 0;
}