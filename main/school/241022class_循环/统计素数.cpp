#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int k;
vector<bool> isnoprime(1e7);
vector<int> prime1;
vector<int> prime2;

void primex(int n,int m)
{
    for (size_t i = 2; i <= n-1; i++)
    {
        if (!isnoprime[i])
        {
            prime2.push_back(i);
        }
        for (auto &&j : prime2)
        {
            if(i*j > m) break;
            isnoprime[i*j] = 1;
            if(i%j == 0) break;
        }
    }
    fill(isnoprime.begin(), isnoprime.end(), false);
    for (size_t i = 2; i <= m; i++)
    {
        if (!isnoprime[i])
        {
            prime1.push_back(i);
        }
        for (auto &&j : prime1)
        {
            if(i*j > m) break;
            isnoprime[i*j] = 1;
            if(i%j == 0) break;
        }
    }
    
}

int main()
{
    int n,m;
    cin >> n>>m;
    primex(n,m);
    cout << prime1.size() - prime2.size()<<endl;
}