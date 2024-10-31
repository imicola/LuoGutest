#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, a[20][20] = { 0 };
    cin >> m >> n;
    for (size_t i = 0; i < m; i++) {
        for (size_t k = 0; k < n; k++) {
            cin >> a[i][k];
        }
    }
    vector<double> arr;
    for (size_t i = 0; i < n; i++) {
        double sum = 0;
        for (size_t k = 0; k < m; k++) {
            sum += a[k][i];
        }
        printf("%.1f\n", sum / m);
    }
    return 0;
}