#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double a[10];
    for (auto&& i : a) {
        cin >> i;
    }
    int x;
    cin >> x;
    for (size_t i = 0; i < 10; i++)
    {
        printf("%.1f ", a[i] / x);
    }
    

    return 0;
}