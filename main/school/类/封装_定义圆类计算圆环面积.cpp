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

class Circle
{
private:
    int radius;

public:
    Circle(int r = 0)
    {
        radius = r;
    }
    double computeArea()
    {
        return 3.14159 * radius * radius;
    }
    double computeAnnulusArea(int r2)
    {
        double outerArea = 3.14159 * r2 * r2;
        double innerArea = computeArea();
        return outerArea - innerArea;
    }
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int r1, r2;
    cin >> r1 >> r2;
    Circle c(r1);
    printf("%.2f\n", c.computeAnnulusArea(r2));
    return 0;
}