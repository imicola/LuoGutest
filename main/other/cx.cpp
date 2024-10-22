#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<bool> isno_prime(1e7);
vector<int> oprime;

void prime(int n)
{
    for (size_t i = 2; i <= n; i++)
    {
        if (!isno_prime[i])
        {
            oprime.push_back(i);
        }
        for (auto &&j : oprime)
        {
            if(i*j > n) break;
            isno_prime[i*j] = 1;
            if(i%j == 0) break;
        }
    }
}
int main()
{
    prime(100);
    for (auto &&i : oprime)
    {
        cout << i << " ";
    }
    
    return 0;
}