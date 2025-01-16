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

LL pows(LL a, LL b)
{
    LL res = 1;
    for (size_t i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << pows(2LL,pows(3LL,4LL));
    return 0;
}