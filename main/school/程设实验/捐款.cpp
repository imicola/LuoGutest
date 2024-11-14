//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    int ans = 0,peo = 0;
    while(ans < 100000){
        cin >> m;
        ans += m;
        peo++;
    }
    printf("%d %.2f", peo, ans / peo * 1.0);
    return 0;
}