//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (size_t i = 0; i < n; i++) {
        int max = -1, min = 1e5, maxindex = 0, minindex = 0;
        for (size_t j = 0; j < n; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxindex = j;
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
                minindex = j;
            }
        }
        if (maxindex != 0) swap(arr[i][0], arr[i][maxindex]);
        if (min != arr[i][n - 1]) {
            if (min == arr[i][maxindex])
                swap(arr[i][n - 1], arr[i][maxindex]);
            else
                swap(arr[i][n - 1], arr[i][minindex]);
        }
    }

    for (auto &&i : arr) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}