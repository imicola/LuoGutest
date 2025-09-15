#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    if (!(cin >> n)) return 0;
    // 1. 二进制位
    vector<int> b;
    long long t = n;
    while (t) {
        b.push_back(t & 1);
        t >>= 1;
    }
    if (b.empty()) b.push_back(0);
    int L = b.size(); // L = floor(log2 n)+1
    int k = L + 2;    // 矩阵阶数
    // 2. 初始化全0矩阵
    vector<vector<int>> A(k, vector<int>(k, 0));
    // 3. 填充次对角线为1
    for (int i = 1; i < k; i++) {
        A[i][i - 1] = 1;
    }
    // 4. 填充最右一列
    A[0][k - 1] = 1;
    for (int i = 1; i <= L; i++) {
        A[i][k - 1] = b[i - 1];
    }

    // 输出
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << A[i][j] << (j + 1 < k ? ' ' : '\n');
        }
    }
    return 0;
}
