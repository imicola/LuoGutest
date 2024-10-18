#include <bits/stdc++.h>
using namespace std;

long long fastpower(long long a , long long b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b&1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout << fastpower(2,8);
}