#include <iostream>
using namespace std;

class Virus
{
public:
    Virus()
    {
        cout << "I am the ancestor of the new virus!" << endl;
    }
    ~Virus()
    {
        cout << "I must disappear!" << endl;
    }
    virtual void eat() = 0;
    //定义纯虚函数
};
class vOne : public Virus
{
public:
    vOne()
    {
        cout << "vOne is born." << endl;
    }
    ~vOne()
    {
        cout << "vOne is dead." << endl;
    }
    void eat()
    {
        cout << "vOne is living in your body." << endl;
    }
};
class vTwo : public Virus
{
public:
    vTwo()
    {
        cout << "vTwo is born." << endl;
    }
    ~vTwo()
    {
        cout << "vTwo is dead." << endl;
    }
    void eat()
    {
        cout << "vTwo is living in your body." << endl;
    }
};

int main()
{
    //定义父类指针v
    Virus *v;
    //定义vOne对象v1
    vOne v1;
    //定义vTwo对象v2
    vTwo v2;
    v = &v1;
    //通过父类指针调用eat()方法
    v->eat();
    v = &v2;
    //通过父类指针调用eat()方法
    v->eat();
    cout << "Our immune system is kill v1 and v2..." << endl;
    return 0;
}