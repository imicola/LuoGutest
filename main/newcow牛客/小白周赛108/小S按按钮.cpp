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
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b == 0) {
            cout << 0 << endl;
            continue;
        }
        if (a == 0) {
            cout << 2 * b - 1 << endl;
            continue;
        }
        if (a == 1) {
            cout << b << endl;
            continue;
        }
        int k = b / (a + 1);
        if (k * (a + 1) >= b) {
            cout << 2 * k << "\n";
        }
        else {
            if (k * (a + 1) + 1 >= b) {
                cout << 2 * k + 1 << "\n";
            }
            else {
                cout << 2 * k + 2 << "\n";
            }
        }
    }
    return 0;
}
// x
// 1
// sum >= T
//