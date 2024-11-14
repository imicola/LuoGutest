//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> m >> n;
    while (m++ <= n) {
        if (m % 3 == 0 && to_string(m).find('5') != string::npos) cout << m << endl;
    }

    return 0;
}