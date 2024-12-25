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
    int a, b, c;
    char s;
    cin >> a >> b >> c >> s;
    if (s == 'a' || s == 'A') {
        cout << (a + b) % c;
    }
    else if (s == 'S' || s == 's') {
        cout << (a >= b ? a - b : a + c - b);
    }
    else if (s == 'M' || s == 'm') {
        cout << (a * b < c ? a * b : a * b - (a * b / c) * c);
    }
    else if (s == 'D' || s == 'd') {
        cout << (a % 2 == 0 ? a / 2 : (a + c) / 2);
    }
    else {
        cout << "Wrong operator!";
    }

    return 0;
}