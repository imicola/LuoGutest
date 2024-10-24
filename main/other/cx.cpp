#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool prime(long long i)
{
    if (i == 2) return 1;
    else if (i == 1) return 0;
    for (size_t k = 2; k * k <= i ; k++)
    {
        if (i%k == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long n;
    cin >> n;
    for (size_t i = 2; i <= n; i++)
    {
        if (prime(i))
        {
            cout << i <<endl;
        }
    }

    return 0;
}