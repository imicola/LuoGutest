//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<double> a(t);
    for (auto &&i : a) {
        cin >> i;
    }
    double min1x = 1e6;
    double *max1 = new double, *min1 = &min1x, sum = 0;
    for (auto &&i : a) {
        *max1 = max(*max1, i);
        *min1 = min(*min1, i);
        sum += i;
    }
    printf("%.2f %.2f %.2f", *max1, *min1, sum / t);
    return 0;
}