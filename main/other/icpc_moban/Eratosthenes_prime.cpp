#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> prime;
vector<bool> IsPrime(1e7);

void Eratosthenes(long long n)
{
    IsPrime[0] = IsPrime[1] = 0; //前两项不为素数，记作0
    for (size_t i = 2; i*i <= n; i++)
    {
        //素数筛选
        //从 i*i 项开始，每次将 i 的倍数标记为非素数
        if (!IsPrime[i])
        {
            for (size_t j = i*i ; j <= n; j += i)
            {
                IsPrime[j] = 1;
            }
        }
    }
    //计入数组
    for (size_t i = 2; i <= n; i++)
    {
        if (!IsPrime[i])
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    Eratosthenes(n);
    for (auto &&i : prime) cout << i <<endl;
    return 0;
}