#include <iostream>
#include <vector>
#include <cmath>   // For std::fabs
#include <iomanip> // For std::fixed, std::setprecision

// 函数声明
double determinant(std::vector<std::vector<double>> &matrix);

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);                   
    int n;
    std::cin >> n;
    if (n <= 0) {
        return 1;
    }
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::vector<std::vector<double>> matrix_copy = matrix;
    double det_value = determinant(matrix_copy);
    std::cout << std::fixed << std::setprecision(6) << det_value << std::endl;
    return 0;
}

double determinant(std::vector<std::vector<double>> &matrix)
{
    int n = matrix.size();
    if (n == 0) {
        return 0.0; // 空矩阵或非法输入
    }
    double det = 1.0; // 初始化行列式为1
    for (int i = 0; i < n; ++i) {
        // 寻找主元 (pivot)，即当前列中绝对值最大的元素，进行部分选主元
        int pivot_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::fabs(matrix[k][i]) > std::fabs(matrix[pivot_row][i])) {
                pivot_row = k;
            }
        }
        // 如果主元行不是当前行，则交换行
        if (pivot_row != i) {
            std::swap(matrix[i], matrix[pivot_row]);
            det *= -1; // 交换两行，行列式变号
        }
        // 如果主元为0，则行列式为0 (矩阵是奇异的)
        if (std::fabs(matrix[i][i]) < 1e-9) { // 使用一个小的阈值来比较浮点数是否接近于0
            return 0.0;
        }
        // 对当前列下方所有行进行消元
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    // 上三角矩阵的行列式是对角线元素的乘积
    for (int i = 0; i < n; ++i) {
        det *= matrix[i][i];
    }

    return det;
}