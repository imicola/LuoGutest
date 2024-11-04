#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;

void r(vector<vector<int>> &a, int k1, int k2) { swap(a[k1], a[k2]); }

void q(vector<vector<int>> &a, int k1, int k2)
{
    vector<int> temp;
    for (size_t i = 0; i < m; i++) {
        temp.push_back(a[i][k1]);
    }
    for (size_t i = 0; i < m; i++) {
        a[i][k1] = a[i][k2];
    }
    for (size_t i = 0; i < m; i++) {
        a[i][k2] = temp[i];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> arr(n + 10, vector<int>(m + 10));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int k;
    cin >> k;
    for (size_t i = 0; i < k; i++) {
        char c;
        cin >> c;
        if (c == 'r') {
            int k1, k2;
            cin >> k1 >> k2;
            r(arr, k1 - 1, k2 - 1);
        }
        else {
            int k1, k2;
            cin >> k1 >> k2;
            q(arr, k1 - 1, k2 - 1);
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}