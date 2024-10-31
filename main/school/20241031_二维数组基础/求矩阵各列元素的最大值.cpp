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
    vector<int> arr;
    for (size_t i = 0; i < n; i++) {
        int max1 = 0;
        for (size_t k = 0; k < m; k++) {
            if (a[k][i] > max1) max1 = a[k][i];
        }
        arr.push_back(max1);
    }
    for (auto&& i : arr)
        cout << i << " ";
    return 0;
}