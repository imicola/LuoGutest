#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (size_t k = 0; k < m; k++) {
            cin >> arr[i][k];
        }
    }
    int x, y;
    cin >> x >> y;
    cout << arr[x - 1][y - 1];
    return 0;
}