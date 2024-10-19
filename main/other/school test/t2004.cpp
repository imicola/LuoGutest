#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin >> a>>b;
    long double t = a*b;
    if (t < 3)
    {
        cout << 0;
        return 0;
    }
    long double p = 0;
    while (p*p*3 < t)
    {
        p++;
    }
    cout <<fixed<<p;
}