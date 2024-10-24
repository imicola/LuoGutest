#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

int main()
{
    ll a = 0,sum = 0,flag = 0,max = -1,min = 1e7;
    while(cin >> a)
    {
        flag++;
        if(a > max) max = a;
        if(a < min) min = a;
        sum += a;
    }
    printf("%lld %lld %.3f",min,max,(double)sum/flag);
    return 0;
}