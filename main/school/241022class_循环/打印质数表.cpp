#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<bool> isnoprime(1e7);
vector<int> prime;

void primex(int n)
{
    for (size_t i = 2; i <= n; i++)
    {
        if (!isnoprime[i])
        {
            prime.push_back(i);
        }
        for (auto &&j : prime)
        {
            if(i*j > n) break;
            isnoprime[i*j] = 1;
            if(i%j == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    primex(n);
    for(auto &&i : prime) cout << i <<" ";
    return 0;
}