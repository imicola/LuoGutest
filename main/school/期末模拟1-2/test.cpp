//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    clock_t be = clock();
    long long ans = 0;
    for (long long i = 0; i < 1e9; i++) {
        ans += i;
    }
    cout << ans << endl;
    clock_t ed = clock();
    cout << ed - be << "ms";
    return 0;
}