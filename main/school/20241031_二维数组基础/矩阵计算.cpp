#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> a[i][k];
            if (a[i][k] > 0) ans += a[i][k] ;
        }
    }
    cout << ans;
    return 0;
}