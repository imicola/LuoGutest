//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    vint a;
    while (1) {
        cin >> n;
        if (n == 0) break;
        a.push_back(n);
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}