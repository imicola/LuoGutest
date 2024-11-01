#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[10];
    for (auto&& i : a) {
        cin >> i;
    }
    double b[10] = { 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65 };
    double sum = 0;
    for (size_t i = 0; i < 10; i++)
    {
        sum += a[i] * b[i];
    }
    printf("%.1f", sum);
    return 0;

}