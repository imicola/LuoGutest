#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(int age): m_nage(age)
    {
        cout << "Animal constructor!" << endl;
    }
    ~Animal()
    {
        cout << "Animal deconstructor!" << endl;
    }

protected:
    int m_nage;
};

class Bird : virtual public Animal
{ //虚继承
public:
    //初始化父类继承的成员
    Bird(int age, int fh): Animal(age)
    {
        cout << "Bird constructor!" << endl;
        m_nflightaltitude = fh;
    }
    ~Bird()
    {
        cout << "Bird deconstructor!" << endl;
    }
    int getFlightAltitude()
    {
        return m_nflightaltitude;
    }

private:
    int m_nflightaltitude;
};

class Fish : virtual public Animal
{ //虚继承
private:
    int m_nswimspeed;

public:
    Fish(int age, int speed): Animal(age) //初始化父类继承的成员
    {
        cout << "Fish constructor!" << endl;
        m_nswimspeed = speed;
    }
    ~Fish()
    {
        cout << "Fish deconstructor!" << endl;
    }
    int getSwimSpeed()
    {
        return m_nswimspeed;
    }
};
//共有继承Bird和Fish，分隔的逗号后没有空格
class Waterbird : public Bird, public Fish
{
public:
    Waterbird(int b_age, int f_age, int fh, int speed): Bird(b_age, fh), Fish(f_age, speed), Animal(b_age)
    {
        cout << "Waterbird constructor!" << endl;
    }
    ~Waterbird()
    {
        cout << "Waterbird deconstructor!" << endl;
    }
    void printAnimalAge()
    {
        cout << "age=" << m_nage << endl;
    }
};
int main()
{
    Waterbird waterbird(5, 6, 20, 30); //定义对象
    cout << waterbird.getFlightAltitude() << ' ' << waterbird.getSwimSpeed() << endl;
    //输出年龄
    waterbird.printAnimalAge();
    return 0;
}