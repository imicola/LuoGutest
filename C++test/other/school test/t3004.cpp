#include <bits/stdc++.h>
using namespace std;

long long pow1(int a ,int b)
{
    long long sum = 1;
    if (b == 0)
    {
        return 1;
    }
    for (size_t i = 0 ; i < b; i++)
    {
        sum *= a;
    }

    return sum;
}

int main()
{
    long long m,n;
    cin >> m >> n;
    cout << -1 <<" " <<-1;
    return 0;
}