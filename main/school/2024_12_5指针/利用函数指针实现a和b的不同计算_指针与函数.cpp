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

int big(int a, int b)
{
    return (a > b ? a : b);
}

int small(int a, int b)
{
    return (a < b ? a : b);
}

int add(int a, int b)
{
    return a + b;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1, a, b;
    cin >> t >> a >> b;
    int (*fup)(int, int);
    if (t == 1)
        fup = big;
    else if (t == 2)
        fup = small;
    else
        fup = add;
    cout << fup(a, b);
    function<int> al(int c, int d);
    
    return 0;
}