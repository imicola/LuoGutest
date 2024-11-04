#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (auto &&i : arr) {
        for (auto &&k : i) {
            cin >> k;
        }
    }
    vector<vector<int>> arr2(m, vector<int>(n));
    for (auto &&i : arr2) {
        for (auto &&k : i) {
            cin >> k;
        }
    }
    double flag = 0;
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            if (arr[i][j] == arr2[i][j]) flag++;
        }
    }
    double ans = flag / (m * n * 1.0) * 100;
    printf("%.2f", ans);
    return 0;
}