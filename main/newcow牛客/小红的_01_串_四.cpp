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
    int x, y, n, begin;
    cin >> x >> y >> n;
    vint v1;
    vint v0;
    for (size_t i = 0; i < n; i++) {
        char k;
        cin >> k;
        if ((k ^ 48) == 1)
            v1.emplace_back(i);
        else
            v0.emplace_back(i);
        if (i == 0) {
            begin = k ^ 48;
        }
    }

    vint result(n, 0x3f3f3f);
    queue<pii> qu;
    qu.push(make_pair(begin, 0));
    while (!qu.empty()) {
        int type = qu.front().first;
        pii k1, k2;
        auto [sk1, p1] = k1;
        auto [sk2, p2] = k2;
        if (type == 0) {
            sk1 = 0;
            sk2 = 1;
            p1 = v0[0];
            p2 = v1[0];
            result[p1] = min(result[p1], result[qu.front().second] + x);
            result[p2] = min(result[p2], result[qu.front().second + y]);
        }
        else {
            sk1 = 1;
            sk2 = 0;
            p1 = v1[0];
            p2 = v0[0];
            result[p1] = min(result[p1], result[qu.front().second] + x);
            result[p2] = min(result[p2], result[qu.front().second + y]);
        }
        v1.erase(v1.begin());
        v0.erase(v0.begin());
        qu.pop();
        qu.push(k1);
        qu.push(k2);
    }
    cout << result[n - 1];
    return 0;
    
}