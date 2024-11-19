//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    map<char, int> mp;
    char p;
    for (size_t i = 0; i < n; i++) {
        cin >> p;
        mp[p]++;
    }
    cout << mp['0'];

    return 0;
}