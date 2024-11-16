//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b, c, d;
    cin >> t >> a >> b >> c >> d;
    if (t == 0) {
        cout << a + b;
        return 0;
    }
    else if (t == 1) {
        cout << (max(a - c, 0) + max(b - d, 0));
    }

    return 0;
}