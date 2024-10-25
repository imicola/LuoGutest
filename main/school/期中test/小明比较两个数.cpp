#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll; 

int main()
{
    ll a,b;
    cin >> a >> b;
    cout << a << (a == b ? "=" : (a > b ? ">" : "<" )) << b << ", " << abs(a-b);
    return 0;
}