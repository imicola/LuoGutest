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
    int n, m, q;
    cin >> n >> m >> q;
    int sum = n * m;
    map<int, int> q1;
    map<int, int> q2;
    for (size_t i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            if (q1[b - 1]) {
                continue;
            }
            q1[b - 1]++;
            int mi = m - q2.size();
            sum -= mi;
        }
        else {
            if (q2[b - 1]) {
                continue;
            }
            q2[b - 1]++;
            int mi = m - q1.size();
            sum -= mi;
        }
    }
    cout << (sum < 0 ? 0 : sum);
    return 0;
}