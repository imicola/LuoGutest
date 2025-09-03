#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> prime;
vector<bool> not_prime(1e7);

void Euler(long long& n)
{
    for (size_t i = 2; i <= n; i++) {
        // 如果该数标记为 0 即 非(非素数),计入素数数组
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        // 筛出小于n的该素数的倍数
        // 当然这么写不优雅，我们可以用范围for替代繁琐的prime[j];
        for (auto&& j : prime) {
            if (i * j > n) break;
            not_prime[i * j] = 1;
            if (i % j == 0) break;
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    Euler(n);
    for (auto&& i : prime) {
        printf("%lld,", i);
    }

    return 0;
}