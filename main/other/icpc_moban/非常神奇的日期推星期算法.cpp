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
    auto dow = [](int y, int m, int d) {
        y -= m < 3;
        return (y + y / 4 - y / 100 + y / 400 + "-bed=pen+mad."[m] + d) % 7;
    };
    cout << dow(2024, 12, 3);
    return 0;
}