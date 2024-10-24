#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

bool prime(ll a)
{
    if(a == 1) return 0;
    if(a == 2) return 1;
    for (size_t i = 2; i*i < a; i++)
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
    ll n;
    cin >> n;
    if (prime(n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    
    return 0;
}