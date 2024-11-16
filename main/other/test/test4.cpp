//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //在构建A的时候可以将A整体向右下移一个单位防止负数下标的出现
    vector<vector<int>> A = {
        {0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4},
        {0, 5, 6, 7, 8},
        {0, 9, 10, 11, 12},
    };
    vector<vector<int>> S(A.size(), vector<int>(A[0].size()));
    S[1][1] = A[1][1];
    for (size_t i = 1; i < A.size(); i++) {
        for (size_t j = 1; j < A[0].size(); j++) {
            if (i == j && i == 1) continue;
            S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }
    for (auto &&i : S) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    /*输出：
    0 0 0 0 0
    0 1 3 6 10
    0 6 14 24 36
    0 15 33 54 78
    */
    return 0;
}