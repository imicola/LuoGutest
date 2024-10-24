#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    int max1 = 0,flag = 0; 
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max1)
        {
            max1 = a[i];
            flag = i;
        }
    }
    cout << flag+1;
    return 0;
}