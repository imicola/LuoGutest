#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

ll jiechen(ll a)
{
    ll k = a;
    if(a == 1) return 1;
    if(a == 2) return 2;
    k *= jiechen(a - 1);
    return k;
}

int main()
{
    int n;
    cin >> n;
    ll p = 0;
    for (size_t i = 1; i <= n; i++)
    {
        p += jiechen(i);
    }
    cout << p;
    return 0;
}