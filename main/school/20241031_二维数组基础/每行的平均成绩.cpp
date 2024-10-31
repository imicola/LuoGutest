#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, a[20][20] = { 0 };
    cin >> m >> n;
    for (size_t i = 0; i < m; i++) {
        double sum = 0;
        for (size_t k = 0; k < n; k++) {
            cin >> a[i][k];
            sum += a[i][k];
        }
        printf("%.1f\n", sum/n);
    }
    
    return 0;
}