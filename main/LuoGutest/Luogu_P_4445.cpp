//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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
    int ans = 0;
    vint arr(t);
    for (size_t i = 0; i < t; i++) {
        cin >> arr[i];
    }
    for (size_t i = 0; i < t - 1; i++) {
        ans += max(arr[i], arr[i + 1]);
    }
    //1010101

    cout << ans;
    return 0;
}