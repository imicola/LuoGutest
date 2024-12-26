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

bool is_huiwen(const string &s)
{
    string sc = s;
    reverse(all(sc));
    return (sc == s);
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    cout << (is_huiwen(s) ? "yes" : "no");
    return 0;
}