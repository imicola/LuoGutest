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

class Box
{
public:
    int length, breadth, height;
    Box(int l = 0, int b = 0, int h = 0)
    {
        length = l;
        breadth = b;
        height = h;
    }
    int v()
    {
        return length * breadth * height;
    }
};

signed
main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << Box(a, b, c).v() << endl;
    return 0;
}