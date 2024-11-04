#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    vector<int> m_max;
    vector<int> n_min;
    for (size_t i = 0; i < m; i++) {
        int max0 = -1;
        for (size_t k = 0; k < n; k++) {
            cin >> arr[i][k];
            if (arr[i][k] > max0) max0 = arr[i][k];
        }
        m_max.push_back(max0);
    }
    for (size_t i = 0; i < n; i++) {
        int min0 = 1e5;
        for (size_t k = 0; k < m; k++) {
            if (arr[k][i] < min0) min0 = arr[k][i];
        }
        n_min.push_back(min0);
    }
    int flag = 0;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            if (arr[i][j] == m_max[i] && arr[i][j] == n_min[j]) {
                cout << i + 1 << " " << j + 1 << " " << arr[i][j] << endl;
                flag++;
            }
        }
    }
    if (flag == 0) cout << "No";
    return 0;
}