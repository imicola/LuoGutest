//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 0, ans = 0;
    int d, flag = 0;
    cin >> d;
    for (size_t i = 1; i <= d; i++) {
        for (size_t j = 1; j <= i; j++) {
            ans += i;
            t++;
            if (t == d) {
                flag++;
                break;
            }
        }
        if (flag) break;
    }
    cout << ans;
    return 0;
}