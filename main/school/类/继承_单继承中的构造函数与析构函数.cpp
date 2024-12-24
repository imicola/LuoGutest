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

const double PI = 3.14;

class Circle
{
public:
    Circle(double x, double y, double r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        cout << R"(Dot constructor called
Circle constructor called)"
             << endl;
    }
    double getArea()
    {
        return PI * r * r;
    }
    ~Circle()
    {
        cout << endl
             << R"(Circle destructor called 
Dot destructor called)"
             << endl;
    }

private:
    double x, y, r;
};

//请编写你的代码
int main()
{
    double x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    printf("%.2f", c.getArea());
    return 0;
}