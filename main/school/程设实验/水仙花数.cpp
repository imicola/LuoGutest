//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 100; i < 1000; i++) {
        string s = to_string(i);
        if (pow(s[0] ^ 48, 3) + pow(s[1] ^ 48, 3) + pow(s[2] ^ 48, 3) == i) cout << i << endl;
    }

    return 0;
}