#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a[25][25] = { 0 };
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < n; k++) {
            cin >> a[i][k];
            if (i == k || n - i - 1 == k) a[i][k] += 10;
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < n; k++) {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    return 0;
}