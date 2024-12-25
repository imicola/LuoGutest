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
    int k;
    cin >> k;
    int ans = 0;
    if (k < 8)
        cout << "count=0";
    else {
        for (size_t i = k / 5; i > 0; i--) {
            for (size_t j = k / 2; j > 0; j--) {
                int p = k - 5 * i - 2 * j;
                if (p > 0) {
                    printf("fen5:%d,fen2:%d,fen1:%d,total:%d\n", i, j, p, i + j + p);
                    ans++;
                }
            }
        }
        printf("count=%d", ans);
    }
    return 0;
}