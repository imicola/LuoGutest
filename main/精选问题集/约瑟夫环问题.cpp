#include <iostream>
using namespace std;


// k为2的特殊情况下最后一个人的编号
int yuesefu(int n)
{
    // 找到最高位的值，即n的最高位所代表的2的幂
    int highestBit = 1;
    while (highestBit <= n) {
        highestBit <<= 1; // 将最高位左移
    }
    // 移动后的结果
    return (n - (highestBit >> 1)) << 1;
}

// k 不为 2 时候的一般解
int yuesefu(int n, int k)
{
    if (k == 2) return yuesefu(n);
    int fin = 0;
    for (size_t i = 2; i <= n; i++) {
        fin = (fin + k) % i;
    }
    return fin;
}

int main()
{
    int n;
    cin >> n;
    cout << yuesefu(n) << endl;
    return 0;
}
