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
    int L, n;
    cin >> L >> n;
    if(n == 0)
    {
        cout << 0 << ' ' << 0;
        return 0;
    }
    vint a(n);
    int minx = 1e6;
    int t = (L / 2 + 1);
    int min_index = -1;
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for (size_t j = 0; j < n; j++) {
        if (minx > abs(a[j] - t)) {
            minx = abs(a[j] - t);
            min_index = j;
        }
    }
    int maxx = max(L + 1 - a[0], a[n - 1]);
    // cout << min_index;
    cout << (a[min_index] >= L / 2 ? L + 1 - a[min_index] : a[min_index]) << " " << maxx;

    return 0;
}