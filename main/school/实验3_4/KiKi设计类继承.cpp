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

class shape
{
    int x, y;

public:
    shape() = default;
    shape(int x, int y): x(x), y(y)
    {
    }
};

class Rectangle : public shape
{
    int width, length;

public:
    Rectangle(int w, int l): width(w), length(l)
    {
    }
    int Get_area()
    {
        return width * length;
    }
};

class Circle : public shape
{
    int r;

public:
    Circle(int r): r(r)
    {
    }
    double Get_area()
    {
        return 3.14 * r * r;
    }
};

class Square : public Rectangle
{
public:
    Square(int a): Rectangle(a, a)
    {
    }
    int Get_area()
    {
        return Rectangle::Get_area();
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int w, l, r, a;
    cin >> w >> l >> r >> a;
    Rectangle rec(w, l);
    Circle cir(r);
    Square squ(a);
    cout << rec.Get_area() << endl;
    cout << cir.Get_area() << endl;
    cout << squ.Get_area() << endl;
    return 0;
}