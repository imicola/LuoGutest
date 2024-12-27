//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((b * c) % d == 0) {
            cout << a - (b * c / d) + 1 << " ";
        }
        else
            cout << a - (b * c / d) << " ";
    }
    return 0;
}