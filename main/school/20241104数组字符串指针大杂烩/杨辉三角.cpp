#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    arr[0][1] = 1;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= i; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= i; j++) {
            printf("%5d",arr[i][j]);
        }
        cout << endl;
    }

    return 0;
}