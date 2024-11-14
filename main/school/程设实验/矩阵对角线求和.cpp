//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> n(9);
    for (auto &&i : n) cin >> i;
    cout << n[0] + n[4] + n[8] << " " << n[2] + n[4] + n[6];
    return 0;
}