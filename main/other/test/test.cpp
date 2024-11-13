//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int f(int a, int b)
{
    if (b == 1) return a;
    return f(a, b - 1) * 2;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int top = 0;
    int sum = 0;
    while (sum != 765) {
        sum = 0;
        int ans = 0;
        for (size_t i = 1; i <= 8; i++) {
            sum += f(top, i);
        }
        ans = f(top, 8);
        if (sum == 765) {
            cout << ans;
            break;
        }
        top++;
    }
    return 0;
}