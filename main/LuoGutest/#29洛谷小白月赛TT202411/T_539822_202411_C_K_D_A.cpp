//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int max0 = -1;
    int ans = -1;
    for (size_t j = 0; j < n; j++) {
        int k = 0, d = 0, a = 0, p = 0;
        scanf("%d/%d/%d", &k, &d, &a);
        if (k - d >= 10)
            p = k * (k - d) + a;
        else {
            if (k >= d)
                p = (k - d + 1) * 3 + a;
            else {
                p = 2 * a;
            }
        }
        if (p > max0) {
            max0 = p;
            ans = j;
        }
    }
    cout << ans + 1;
    return 0;
}