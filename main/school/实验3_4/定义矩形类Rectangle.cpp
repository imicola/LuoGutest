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

class Rectangle
{
    int width, height;

public:
    Rectangle(int w, int h): width(w), height(h)
    {
        cout << "Rectangle's constructor is called!" << endl;
    }
    ~Rectangle()
    {
        cout << "Rectangle's destructor is called!" << endl;
    }
    int area()
    {
        return width * height;
    }
    int getheight()
    {
        return height;
    }
    int getwidth()
    {
        return width;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, b;
    cin >> a >> b;
    Rectangle rec(b, a);
    printf("Length = %d\nwidth = %d\nArea = %d\n", rec.getheight(), rec.getwidth(), rec.area());

    return 0;
}