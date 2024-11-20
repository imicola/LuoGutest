//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pii;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (size_t i = 0; i * 5 <= n; i++) {
            for (size_t j = 0; i * 5 + 3 * j <= n; j++) {
                if (i * 5 + 3 * j == n) mp[i + j] = 1;
            }
        }
        auto it = mp.begin();
        if (it->second == 0)
            cout << -1;
        else
            cout << it->first;
    }
    return 0;
}