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

struct high
{
    string name;
    int tall;
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vector<high> g(t);
    for (auto &&i : g) {
        cin >> i.name >> i.tall;
    }
    sort(all(g), [](const high &a, const high &b) { return a.tall > b.tall; });
    cout << g[0].name << " " << g[0].tall;
    return 0;
}