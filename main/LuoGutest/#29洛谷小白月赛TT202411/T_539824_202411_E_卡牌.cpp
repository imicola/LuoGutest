//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> k;
    for (size_t i = 0; i < m; i++) {
        vector<int> a(5);
        for (size_t j = 0; j < 5; j++) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int t = 4;
        while (t >= 0) {
            if (n >= a[t]) {
                k[a[t]]++;
                n -= a[t];
                break;
            }
            t--;
        }
    }
    for (size_t i = 1; i <= 5; i++) {
        cout << k[i] << " ";
    }
    cout << endl << n;
    return 0;
}