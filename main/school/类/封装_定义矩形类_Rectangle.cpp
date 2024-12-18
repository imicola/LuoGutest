
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length, width;
public:
    void setValues(int, int);
    int area()
    {
        return length * width;
    }
};

void Rectangle::setValues(int x, int y)
{
    length = x;
    width = y;
}

int main()
{
    Rectangle rect;
    rect.setValues(3, 4);
    cout << "area: " << rect.area();
    return 0;
}