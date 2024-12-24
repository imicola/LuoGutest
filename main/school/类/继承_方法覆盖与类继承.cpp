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
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~shape()
    {
    }
};

class Rect : public shape
{
    double x1, y1, x2, y2;

public:
    Rect(double _x1, double _y1, double _x2, double _y2): x1(_x1), y1(_y1), x2(_x2), y2(_y2)
    {
    }
    double area() override
    {
        return fabs((x2 - x1) * (y2 - y1));
    }
    double perimeter() override
    {
        return 2.0 * (fabs(x2 - x1) + fabs(y2 - y1));
    }
};

class Circle : public shape
{
    double x, y, r;

public:
    Circle(double _x, double _y, double _r): x(_x), y(_y), r(_r)
    {
    }
    double area() override
    {
        return 3.1415926 * r * r;
    }
    double perimeter() override
    {
        return 2.0 * 3.1415926 * r;
    }
};

class Triangle : public shape
{
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3)
    : x1(_x1)
    , y1(_y1)
    , x2(_x2)
    , y2(_y2)
    , x3(_x3)
    , y3(_y3)
    {
    }
    double area() override
    {
        return 0.5 * fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
    }
    double perimeter() override
    {
        auto dist = [](double ax, double ay, double bx, double by) {
            return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
        };
        return dist(x1, y1, x2, y2) + dist(x2, y2, x3, y3) + dist(x3, y3, x1, y1);
    }
};
signed main()
{
    int n;
    cin >> n;
    while (n--) {
        string shapeType;
        cin >> shapeType;
        if (shapeType == "Rect") {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            unique_ptr<shape> sp = make_unique<Rect>(x1, y1, x2, y2);
            cout << fixed << setprecision(5) << sp->area() << " " << sp->perimeter() << endl;
        }
        else if (shapeType == "Circle") {
            double x, y, r;
            cin >> x >> y >> r;
            unique_ptr<shape> sp = make_unique<Circle>(x, y, r);
            cout << fixed << setprecision(5) << sp->area() << " " << sp->perimeter() << endl;
        }
        else if (shapeType == "Triangle") {
            double x1, y1, x2, y2, x3, y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            unique_ptr<shape> sp = make_unique<Triangle>(x1, y1, x2, y2, x3, y3);
            cout << fixed << setprecision(5) << sp->area() << " " << sp->perimeter() << endl;
        }
    }
    return 0;
}
