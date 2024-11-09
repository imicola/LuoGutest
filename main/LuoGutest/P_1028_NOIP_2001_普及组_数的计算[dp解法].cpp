//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

//f(n) = f(1) + f(2) + ... + f(n/2) + 1

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> f(n + 1);
    f[1] = 1;
    f[2] = 2;
    //主要是构造下面这个循环构造 f(n) 
    for (size_t i = 3; i <= n; i++) {
        for (size_t j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
        f[i]++;
    }
    cout << f[n];
    return 0;
}