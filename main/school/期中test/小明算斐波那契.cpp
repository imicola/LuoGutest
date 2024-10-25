#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

int main()
{
    ll d;
    cin >> d;
    ll a[51];
    a[1] = 1;
    a[2] = 1;
    for (size_t i = 3; i <= d+1; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[d-1] << " " <<a[d];
    printf(" %.3f",(double)a[d]/a[d-1]);
    return 0;
}