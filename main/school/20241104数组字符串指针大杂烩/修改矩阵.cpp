#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    int x = 0, y = 0, z = 0;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n, vector<int>(m));
    for (size_t i = 1; i <= n; i++) {
        for (size_t k = 1; k <= m; k++) {
            arr[i - 1][k - 1] = i + k;
        }
    }
    for (size_t j = 0; j < q; j++) {
        x = y = z = 0;
        cin >> x >> y >> z;
        arr[x - 1][y - 1] = z;
    }
    for (auto &&i : arr) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}