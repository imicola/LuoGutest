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

class Cube
{
public:
    Cube(int h, int w, int l)
    {
        height = h;
        width = w;
        length = l;
        cout << "Parameter constructor is called." << endl;
    }
    Cube(Cube &cb)
    {
        cout << "Copy constructor is called." << endl;
    }
    ~Cube()
    {
        cout << "Deconstructor is called." << endl;
    }
    int compute_bottom_area()
    {
        return width * length;
    }
    int compute_volume()
    {
        return width * length * height;
    }
    int get_width()
    {
        return width;
    }
    int get_length()
    {
        return length;
    }
    int get_height()
    {
        return height;
    }
    void set_all(int h, int w, int l)
    {
        height = h / 10;
        width = w / 10;
        length = l / 10;
    }

private:
    int height;
    int width;
    int length;
};

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Cube cb1(0, 0, 0);
    int h, w, l;
    cin >> l >> w >> h;
    Cube cb2(cb1);
    cb1.set_all(h, w, l);
    printf("The length of c2 is %d.\n", cb1.get_length());
    printf("The width of c2 is %d.\n", cb1.get_width());
    printf("The heigth of c2 is %d.\n", cb1.get_height());
    printf("The bottom area of c2 is %d.\n", cb1.compute_bottom_area());
    printf("The volumn of c2 is %d.\n", cb1.compute_volume());
    // cb1.~Cube();
    return 0;
}