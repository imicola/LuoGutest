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
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x <= 6 || x >= 70) cnt++;
    }
    cout << cnt;
    return 0;
}