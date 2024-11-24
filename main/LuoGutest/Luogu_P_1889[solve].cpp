//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vint x(n);
    vint y(n);
    for (size_t i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(all(y));
    sort(all(x));
    int midy = 0;
    if (n % 2 == 0)
        midy = (y[n / 2] + y[n / 2 - 1]) / 2;
    else
        midy = y[n / 2];
    // cout << midy;
    // midy = y[n / 2];
    int ansy = 0;
    for (int i = 0; i < n; i++) ansy += abs(y[i] - midy);
    int ansx = 0;
    for (int i = 1; i <= n; i++) {
        x[i - 1] -= i;
    }
    sort(all(x));
    int midx = 0;
    if (n % 2 == 0)
        midx = (x[n / 2] + x[n / 2 - 1]) / 2;
    else
        midx = x[n / 2];
    for (int i = 0; i < n; i++) ansx += abs(x[i] - midx);
    cout << ansx + ansy;
    return 0;
}