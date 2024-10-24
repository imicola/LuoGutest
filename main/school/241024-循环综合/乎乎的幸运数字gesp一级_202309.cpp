#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int k,l,r;

bool solve(int a)
{
    if(a%k == 0 || a%10 == k) return 1;
    else return 0;
}

int main()
{
    cin >> k >> l >> r;
    int sum = 0;
    for (size_t i = l; i <= r; i++)
    {
        if(solve(i)) sum += i;
    }
    cout << sum;
    return 0;
}