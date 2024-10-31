#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double a[5][5];
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            cin >> a[i][k];
        }
    }
    for (int i = 0; i < 5; i++) {
        double ans = 0;
        for (size_t k = 0; k < 5; k++) {
            printf("%.1f ", a[i][k]);
            ans += a[i][k];
        }
        printf("%.1f\n", ans);
    }

    return 0;
}