#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n+1, vector<char>(m+1));
    vector<vector<int>> arr0(n + 2, vector<int>(m + 2, 0));
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                arr0[i][j] = -10000;
                arr0[i - 1][j]++;
                arr0[i + 1][j]++;
                arr0[i][j - 1]++;
                arr0[i][j + 1]++;
                arr0[i - 1][j - 1]++;
                arr0[i + 1][j + 1]++;
                arr0[i - 1][j + 1]++;
                arr0[i + 1][j - 1]++;
            }
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t k = 1; k <= m; k++) {
            if (arr0[i][k] < 0)
                cout << '*';
            else
                cout << arr0[i][k];
        }
        cout << endl;
    }

    return 0;
}