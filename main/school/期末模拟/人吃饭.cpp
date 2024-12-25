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

class Person
{
    int a;

public:
    virtual void eat() = 0;
    virtual void pay() = 0;
};

class Chinese : public Person
{
public:
    Chinese()
    {
        cout << "中国人进入餐厅" << endl;
    }
    ~Chinese()
    {
        cout << "中国人离开餐厅" << endl;
    }
    void eat() override
    {
        cout << "中国人用筷子吃饭" << endl;
    }
    void pay() override
    {
        cout << "中国人用微信支付" << endl;
    }
};

class American : public Person
{
public:
    American()
    {
        cout << "美国人进入餐厅" << endl;
    }
    ~American()
    {
        cout << "美国人离开餐厅" << endl;
    }
    void eat() override
    {
        cout << "美国人用叉子吃饭" << endl;
    }
    void pay() override
    {
        cout << "美国人用信用卡支付" << endl;
    }
};

class Indian : public Person
{
public:
    Indian()
    {
        cout << "印度人进入餐厅" << endl;
    }
    ~Indian()
    {
        cout << "印度人离开餐厅" << endl;
    }
    void eat() override
    {
        cout << "印度人用手吃饭" << endl;
    }
    void pay() override
    {
        cout << "印度人用现金支付" << endl;
    }
};

void processMeal(Person &p)
{
    p.eat();
    p.pay();
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    Chinese ch;
    American am;
    Indian in;
    processMeal(ch);
    processMeal(am);
    processMeal(in);
    return 0;
}