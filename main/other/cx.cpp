#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// 存储质数的向量
vector<int> prime;
// 存储非质数标记的布尔向量
vector<bool> notprime(1e7);

// 埃拉托斯特尼筛法函数，用于找出小于等于n的所有质数
void euler(int n)
{
    for (size_t i = 2; i <= n; i++)
    {
        if(!notprime[i])
        {
            prime.push_back(i);
        }
        for (auto &&j : prime)
        {
            if(i*j > n) break;
            notprime[i*j] = 1;
            if( i%j == 0) break;
        }
    }
}

// 主函数
int main()
{
    int n;
    cin >> n; // 输入n的值
    euler(n); // 调用埃拉托斯特尼筛法函数
    for (auto &&i : prime) cout << i << endl; // 输出所有找到的质数
    return 0;
}