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

class Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void setPoint(int x, int y)
    {
        cin >> x >> y;
        this->x = x;
        this->y = y;
    }
    void movepoint(int x, int y)
    {
        cin >> x >> y;
        this->x += x;
        this->y += y;
    }
    void showpoint()
    {
        cout << x << " " << y << endl;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Point p(0, 0);
    p.setPoint(0, 0);
    p.movepoint(0, 0);
    p.showpoint();
    return 0;
}