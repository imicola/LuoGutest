#include <bits/stdc++.h>
using namespace std;

int prime(int a)
{
    if(a == 2)
    {
        return 1;
    }
    for (size_t i = 2; i*i <= a; i++)
    {
        if (a%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = 0,sum = 0;
    cin >> n;
    int p = n;
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (prime(p) == 1)
        {
            sum += p;
            break;
        }
        if(prime(i) == 1)
        {
            while (p%i == 0)
            {
                p /= i;
                sum += i;
            }
        }
    }

    if (n <= 5)
    {
        cout << n;
    }
    else
    {
        cout << sum;
    }
    return 0;
}