//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long f(int n)
{
    if (n == 0 || n == 1) return 1;
    return n * f(n - 1);
}

long long fun(int n)
{
    string s = to_string(n);
    long long ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        ans += f(s[i] ^ 48);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}