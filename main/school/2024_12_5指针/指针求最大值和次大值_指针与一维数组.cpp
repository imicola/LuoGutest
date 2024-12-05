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

void LargestTow(vint &a ,int *pf , int *ps)
{
    *pf = *max_element(all(a));
    a.erase(max_element(all(a)));
    *ps = *max_element(all(a));
    // cout << *pf << *ps;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vint a(t);
    for (auto &&i : a) {
        cin >> i;
    }
    int *f = new int, *s = new int;
    LargestTow(a, f, s);
    cout << *f << " " << *s;
    return 0;
}