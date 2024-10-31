#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[n][n] = { 0 };
    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < n; k++) {
            cin >> a[i][k];
            if (i == 0 || i == n - 1 || k == 0 || k == n - 1) a[i][k] += 6;
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < n; k++) {
            cout << setw(3) << a[i][k];
        }
        cout << endl;
    }
    return 0;
}