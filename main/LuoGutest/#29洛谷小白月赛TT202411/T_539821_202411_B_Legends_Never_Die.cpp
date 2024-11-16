//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    cout << (a + b >= k ? "Yes" : "No") << endl;
    cout << (a + c >= k ? "Yes" : "No") << endl;
    cout << (c + b >= k ? "Yes" : "No") << endl;
    return 0;
}