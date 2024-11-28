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

void sort3(LL *p1, LL *p2, LL *p3)
{
    LL a, b, c;
    a = max({*p1, *p2, *p3});
    c = min({*p1, *p2, *p3});
    b = (*p1 + *p2 + *p3 - a - c);
    *p1 = c;
    *p2 = b;
    *p3 = a;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    LL a, b, c;
    cin >> a >> b >> c;
    sort3(&a, &b, &c);
    cout << a << " " << b << " " << c;
    return 0;
}