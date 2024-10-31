#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> a[i][k];
        }
    }
    int max = -1, x, y;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (a[i][k] > max) {
                max = a[i][k];
                y = i;
                x = k;
            }
        }
    }
    cout << max << " " << y + 1 << " " << x + 1;
    return 0;
}