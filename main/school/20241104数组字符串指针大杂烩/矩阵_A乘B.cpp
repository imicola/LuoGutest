#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, p;

int sum(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, int i, int j)
{
    int sumx = 0;
    for (size_t p = 0; p < m; p++) {
        sumx += matrix_A[i][p]*matrix_B[p][j];
    }
    return sumx;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> matrix_A(n, vector<int>(m));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> matrix_A[i][j];
        }
    }
    cin >> p;
    vector<vector<int>> matrix_C(n, vector<int>(p));
    vector<vector<int>> matrix_B(m, vector<int>(p));
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < p; j++) {
            cin >> matrix_B[i][j];
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < p; j++) {
            matrix_C[i][j] = sum(matrix_A, matrix_B, i, j);
        }
    }
    for (auto &&i : matrix_C) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}