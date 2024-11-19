//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

void f(int n)
{
    if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) {
        cout << "It is a leap year";
        return;
    }
    cout << "It is not a leap year";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    f(n);
    return 0;
}