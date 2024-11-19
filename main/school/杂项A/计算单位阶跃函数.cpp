//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

double f(int a){
    if (a < 0) return 0;
    if (a > 0) return 1;
    return 0.5;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    // cin >> t;
    while (cin >> t)
    {
        cout << f(t) << endl;
    }
    
    return 0;
}